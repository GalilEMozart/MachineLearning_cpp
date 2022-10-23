#include <Eigen/Dense>
#include <string>
#include <vector>

class Preprocess {

    //std::string nameFile;
public:
    //Preprocess();
    //~Preprocess();
    Eigen::MatrixXd read_csv(std::string pathFileName);
    void write_csv(std::string pathFileName,Eigen::MatrixXd data_matrix);    
    //Eigen::MatrixXd normaliseData(Eigen::MatrixXd data);
    //std::vector<Eigen::VectorXd, Eigen::VectorXd> getFeatureLabel(Eigen::MatrixXd data, std::string pathFileName);
    //void printFile(std::string pathFileName);

};