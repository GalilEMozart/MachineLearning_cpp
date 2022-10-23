set(EIGEN3_INCLUDE_DIR "/usr/local/include/eigen3")
add_library(regression src/linearRegression.cpp)
target_link_libraries(regression ${EIGEN3_INCLUDE_DIR})
target_link_libraries(regression basemodel)
target_include_directories(regression PUBLIC 
    ${EIGEN3_INCLUDE_DIR}
    "${CMAKE_SOURCE_DIR}/LinearRegression/header"
    "${CMAKE_SOURCE_DIR}/../BaseClass/header")