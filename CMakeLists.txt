cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Release)
project(MachineLearning_cpp VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Preprocess)
add_subdirectory(BaseClass)
add_subdirectory(LinearRegression)

add_executable(main Test/main.cpp)
target_link_libraries(main PUBLIC preprocess)
target_include_directories(main PUBLIC 
    "${PROJECT_BINARY_DIR}"
)
