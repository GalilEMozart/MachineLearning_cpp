set(EIGEN3_INCLUDE_DIR "/usr/local/include/eigen3")

add_library(basemodel src/basemodel.cpp)
target_link_libraries(basemodel ${EIGEN3_INCLUDE_DIR})
target_include_directories(basemodel PUBLIC 
    ${EIGEN3_INCLUDE_DIR}
    "${CMAKE_SOURCE_DIR}/BaseClass/header")