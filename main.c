#include <windows.h>
#include <stdio.h>

#define COM_PORT "COM8"      // Change this to the appropriate COM port number for your system
#define BAUD_RATE CBR_115200 // You can change the baud rate to any other supported value

HANDLE open_uart(const char *port, DWORD baud_rate);
int close_uart(HANDLE uart_handle);

int main()
{
    // Open UART
    HANDLE uart_handle = open_uart(COM_PORT, BAUD_RATE);
    if (uart_handle == INVALID_HANDLE_VALUE)
    {
        return 1;
    }

    char buffer[128] = {0};
    DWORD bytes_read;

    // Read from UART in a loop
    while (1)
    {
        if (ReadFile(uart_handle, buffer, sizeof(buffer) - 1, &bytes_read, NULL) && bytes_read > 0)
        {
            buffer[bytes_read] = '\0'; // Ensure the buffer is null-terminated
            printf("%s", buffer);
        }
    }

    // Close UART
    close_uart(uart_handle);
    return 0;
}

HANDLE open_uart(const char *port, DWORD baud_rate)
{
    HANDLE uart_handle;
    DCB dcb = {0};
    COMMTIMEOUTS timeouts = {0};

    char port_path[32];
    snprintf(port_path, sizeof(port_path), "\\\\.\\%s", port);
    uart_handle = CreateFileA(port_path, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (uart_handle == INVALID_HANDLE_VALUE)
    {
        return uart_handle;
    }

    if (!GetCommState(uart_handle, &dcb))
    {
        CloseHandle(uart_handle);
        return INVALID_HANDLE_VALUE;
    }

    dcb.BaudRate = baud_rate;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.Parity = NOPARITY;

    if (!SetCommState(uart_handle, &dcb))
    {
        CloseHandle(uart_handle);
        return INVALID_HANDLE_VALUE;
    }

    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(uart_handle, &timeouts))
    {
        CloseHandle(uart_handle);
        return INVALID_HANDLE_VALUE;
    }

    // Purge any data in the input and output buffers
    if (!PurgeComm(uart_handle, PURGE_TXCLEAR | PURGE_RXCLEAR))
    {
        CloseHandle(uart_handle);
        return INVALID_HANDLE_VALUE;
    }

    return uart_handle;
}

int close_uart(HANDLE uart_handle)
{
    return CloseHandle(uart_handle) ? 0 : 1;
}
