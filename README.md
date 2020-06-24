# Matrices and Vectors
Build commands: Executable will be kept in the `bin` directory

For `Release` build, enable `set(CMAKE_BUILD_TYPE "Release")` in `CMakeLists.txt`

For `Debug` build (with ASAN flags), enable `set(CMAKE_BUILD_TYPE "Release")` in `CMakeLists.txt`
    

    mkdir build
    cd build
    cmake ..
    make -j8
    
Clean commands:

    make clean
    
