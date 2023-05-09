# UART Communication Project

This project demonstrates how to communicate with a UART device using C on Windows. It includes code for receiving data from a UART device and simple batch files for building and cleaning the project.

## Prerequisites

- A Windows machine with a UART device connected (e.g., a USB-to-Serial converter)
- CMake installed and added to the PATH
- A C compiler (e.g., GCC or Visual Studio)

## Building the Project

This project uses CMake as the build system. We have provided simple batch files to build the project in Debug and Release configurations:

1. To build the project in Debug configuration, double-click on the `create_debug.bat` file.
2. To build the project in Release configuration, double-click on the `create_release.bat` file.

The compiled executables will be created in the `build_debug` or `build_release` directories, depending on the chosen configuration.

## Cleaning the Project

To clean up the build directories, double-click on the `clean.bat` file. This will remove the `build_debug` and `build_release` directories, along with their contents.

## Usage

1. Connect your UART device to the computer and determine the COM port number assigned to it.
2. Modify the `COM_PORT` definition in the source code to match the COM port number of your device.
3. Build the project using the provided batch files.
4. Run the compiled executable from the appropriate build directory (e.g., `build_debug` or `build_release`).

The program will continuously read data from the UART device and print it to the console. To exit the program, press `Ctrl+C`.
