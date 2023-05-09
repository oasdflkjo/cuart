@echo off

if exist build_release (
    echo Cleaning build_release...
    rmdir /s /q build_release
    echo build_release cleaned.
) else (
    echo build_release not found.
)

echo.

if exist build_debug (
    echo Cleaning build_debug...
    rmdir /s /q build_debug
    echo build_debug cleaned.
) else (
    echo build_debug not found.
)

echo.
echo Clean up completed.
pause