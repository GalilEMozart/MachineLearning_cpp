#include <Eigen/Dense>
#include "basemodel.hpp"

class LinearRegression:BaseModel {

    bool biais;

public:
    LinearRegression(bool biais) : biais(biais){};
        // todo:force the weight to be positivie
    void fit(Eigen::MatrixXd data){
        this->getparameter() = Eigen::VectorXd::Random(data.cols());
    };
    Eigen::VectorXd predict(Eigen::MatrixXd data){
        return Eigen::VectorXd::Ones(data.rows());
    }

};