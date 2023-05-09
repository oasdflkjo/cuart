@echo off

mkdir build_debug
cd build_debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cd ..

echo.
echo Debug build completed.
pause