#include <Eigen/Dense>
#include "basemodel.hpp"
#include <iostream>

class LinearRegression:BaseModel {

    bool biais;
    bool trained;

public:
    LinearRegression(bool biais = true ) : biais(biais), trained(false){};
        // todo:force the weight to be positivie
    void fit(Eigen::MatrixXd data, Eigen::VectorXd label,int n_iter, float lr);
    Eigen::VectorXd predict(Eigen::MatrixXd data);

};