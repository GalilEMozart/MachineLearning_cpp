#include "preprocess.hpp"
#include "linearRegression.hpp"
#include <Eigen/Dense>
#include <iostream>

int main(int argc, char *argv[]){
    Preprocess preprocess;
    Eigen::MatrixXd data_label = preprocess.read_csv("/Users/ArnoldMubs/Documents/Yves_Fichier/MachineLearning_cpp/data/test_clean.csv");
    
    //split features and label
    int col = data_label.cols();
    int row = data_label.rows();
    Eigen::VectorXd label = data_label.col(col-1);
    Eigen::MatrixXd data = data_label.block(0,0,row,col-1);

    std::cout << "Taille de donnees initiale (" << data_label.rows() << "," << data_label.cols() <<")" << std::endl;
    std::cout << "Taille de donnees split (" << data.rows() << "," << data.cols() <<")" <<std::endl;

    LinearRegression linearmodel(true);

    Eigen::VectorXd pred = linearmodel.predict(data);    
    std::cout << "-- Erreur de prediction "<< (label-pred).array().square().mean()/row << std::endl;
    linearmodel.fit(data, label, 10e+3, 10e-3);

    pred = linearmodel.predict(data);    
    std::cout << "-- Erreur de prediction "<< (label-pred).array().square().mean()/row << std::endl;

    return 0;
}

//g++ -I ../header -I /usr/local/include/eigen3  ../src/preprocess.cpp read.cpp -o main