#include "preprocess.hpp"

int main(int argc, char *argv[]){
    Preprocess preprocess;
    preprocess.read_csv("/Users/ArnoldMubs/Documents/Yves_Fichier/MachineLearning_cpp/data/test_clean.csv");
    return 0;
}

//g++ -I ../header -I /usr/local/include/eigen3  ../src/preprocess.cpp read.cpp -o main