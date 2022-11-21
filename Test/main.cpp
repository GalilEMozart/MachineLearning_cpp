#include "preprocess.hpp"
#include "linearRegression.hpp"
#include <Eigen/Dense>
#include <iostream>

int main(int argc, char *argv[]){
    Preprocess preprocess;
    Eigen::MatrixXd data_label = preprocess.read_csv("/Users/ArnoldMubs/Documents/Yves_Fichier/MachineLearning_cpp/data/data_test.csv");
    
    //split features and label
    int col = data_label.cols();
    int row = data_label.rows();
    Eigen::MatrixXd label = Eigen::MatrixXd::Random(row,1);
    label.col(0) = data_label.col(col-1);
    Eigen::MatrixXd data = data_label.block(0,0,row,col-1);

    std::cout << "Taille de donnees initiale (" << data_label.rows() << "," << data_label.cols() <<")" << std::endl;
    std::cout << "Taille de donnees split (" << data.rows() << "," << data.cols() <<")" <<std::endl;
    //preprocess.print(data_label);
    LinearRegression linearmodel(true);
    
    Eigen::MatrixXd pred = linearmodel.predict(data);
    std::cout << "-- Erreur de prediction "<< (label-pred).array().square().mean() << std::endl;
    linearmodel.fit(data, label, 10e+2, 10e-2);
    
    pred = linearmodel.predict(data);    
    std::cout << "-- Erreur de prediction "<< (label-pred).array().square().mean() << std::endl;

    return 0;
}

//g++ -I ../header -I /usr/local/include/eigen3  ../src/preprocess.cpp read.cpp -o main