set(EIGEN3_INCLUDE_DIR "/usr/local/include/eigen3")
add_library(linearRegression src/linearRegression.cpp)
target_link_libraries(linearRegression ${EIGEN3_INCLUDE_DIR})
target_link_libraries(linearRegression basemodel)
target_include_directories(linearRegression PUBLIC 
    ${EIGEN3_INCLUDE_DIR}
    "${CMAKE_SOURCE_DIR}/LinearRegression/header"
    "${CMAKE_SOURCE_DIR}/../BaseClass/header")