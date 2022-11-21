#include "linearRegression.hpp"
#include <iostream>

void LinearRegression::fit(Eigen::MatrixXd data, Eigen::MatrixXd label,int n_iter, float lr){

    int m = data.rows();
    int n = data.cols();
    Eigen::MatrixXd theta = Eigen::MatrixXd::Random(n,1);

    std::cout << "Taille de donnees data dans linearRegression (" << data.rows() << "," << data.cols() <<")" <<std::endl;
    std::cout << "Taille de donnees label dans linearRegression (" << label.rows() << "," << label.cols() <<")" <<std::endl;


    Eigen::MatrixXd pred = data*theta;
    
    std::cout << "Erreur de prediction "<< (label-pred).array().square().mean() << std::endl;
    for(int i=0;i<n_iter;i++){

        //Eigen::MatrixXd pred = data*theta;
        //std::cout << "Erreur de prediction "<< (label-pred).array().square().mean() << std::endl;
        theta = theta - lr*(1/m)*(data.transpose()*(data*theta-label));
        //std::cout << "Iteration "<< i << std::endl;
    }

    pred = data*theta;
    std::cout << "Erreur de prediction "<< (label-pred).array().square().mean() << std::endl;
    
    this->setparameter(theta);
    this->trained = true;
};

Eigen::MatrixXd LinearRegression::predict(Eigen::MatrixXd data){
    if(this->trained)
        return data*this->getparameter();
    else {
        std::cout << "warning:The model has not fit yet ! Parameters are initialized randomly"<<std::endl;
        return data*Eigen::MatrixXd::Random(data.rows(),1);
    }
}