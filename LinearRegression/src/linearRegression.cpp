#include "linearRegression.hpp"
#include <iostream>

void LinearRegression::fit(Eigen::MatrixXd data, Eigen::VectorXd label,int n_iter, float lr){

    Eigen::VectorXd theta = Eigen::VectorXd::Random(data.rows());
    int m = data.rows();

    for(int i=0;i<n_iter;i++){

        Eigen::VectorXd pred = data*theta;
        std::cout << "Erreur de prediction "<< (label-pred).array().square().mean()/m << std::endl;
        theta = theta - (lr*(1/m)*(data.transpose()*(data*theta-label)));
        std::cout << "Iteration "<< i << std::endl;
    }

    this->setparameter(theta);
    this->trained = true;
};

Eigen::VectorXd LinearRegression::predict(Eigen::MatrixXd data){
    if(this->trained)
        return data*this->getparameter();
    else {
        std::cout << "warning:The model has not fit yet ! Paremters are initialized randomly"<<std::endl;
        return data*Eigen::VectorXd::Random(data.rows());
    }
}