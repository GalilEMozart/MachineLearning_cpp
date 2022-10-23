set(EIGEN3_INCLUDE_DIR "/usr/local/include/eigen3")
add_library(preprocess src/preprocess.cpp)
target_link_libraries(preprocess ${EIGEN3_INCLUDE_DIR})
target_include_directories(preprocess PUBLIC 
    ${EIGEN3_INCLUDE_DIR}
    "${CMAKE_SOURCE_DIR}/Preprocess/header")