
#include "preprocess.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Eigen::MatrixXd Preprocess::read_csv(std::string pathFileName){
    
    int col = -1, row = 0;
    int i = 0,j=0;
    std::ifstream fichier(pathFileName,std::ios::in);
    std::vector<std::vector<float>> data_vector;

    if(fichier){
        
        std::cout << "Ouverture reussie" << std::endl;
        std::string line, cell;
        std::stringstream lineStream;
        
        

        //count col and delete the header
        while(std::getline(fichier,line)){
            lineStream << line;
            while (std::getline(lineStream, cell, ','))
            {
                col+=1;
            }
            lineStream.clear();
            break;
        }

        //store data and count row
        while(std::getline(fichier,line)){
            lineStream << line;
            std::vector<float> vec;
            while (std::getline(lineStream, cell, ','))
            {
                vec.push_back(std::stof(cell));
            }
            lineStream.clear();
            data_vector.push_back(vec);
            row+=1;
        }

        //fichier.seekg(0,std::ios::beg);
        fichier.close();
    }
    else std::cerr << "Erreur d'ouverture";
    

    Eigen::MatrixXd data_matrix(row,col);
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            data_matrix(i,j) = data_vector[i][j];
        }

    }
    std::cout << "Taille du fichier (" << row << "," << col << ")"<<std::endl; 

    return data_matrix;
}

void Preprocess::write_csv(std::string pathFileName, Eigen::MatrixXd data_matrix){
    
        std::ofstream fichier(pathFileName,std::ios::out|std::ios::trunc);
        if(fichier){
            std::cout << "Ouverture reussie" << std::endl;

            for(int i=0;i<data_matrix.rows();i++){
                    for(int j=0;j<data_matrix.cols();j++){
                        fichier << data_matrix(i,j) << ",";
                    }

                    fichier << std::endl;
                }

            fichier.close();
        }
        else std::cerr << "Erreur d'ouverture";

    return;
}


