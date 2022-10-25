#include <Eigen/Dense>

class BaseModel{

    Eigen::VectorXd parameter;

public:
    
    virtual void fit(Eigen::MatrixXd data, Eigen::VectorXd label,int n_iter, float lr)=0;
    virtual Eigen::VectorXd predict(Eigen::MatrixXd data)=0;
    
    float score(Eigen::MatrixXd data,Eigen::VectorXd label){
        
        Eigen::VectorXd pred = predict(data);
        auto n = label.size();
        Eigen::VectorXd pred_mean = label.mean()*Eigen::VectorXd::Ones(n);
        float score_r2 = 1- ((label-pred).array().square().mean()/(label-pred_mean).array().square().mean());

        return score_r2;
    };

    Eigen::VectorXd getparameter(){
        return this->parameter;
    };

    void setparameter(Eigen::VectorXd new_parameter){
        this->parameter = new_parameter;
    };

};