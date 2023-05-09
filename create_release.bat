@echo off

mkdir build_release
cd build_release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cd ..

echo.
echo Release build completed.
pause