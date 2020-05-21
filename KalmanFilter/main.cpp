
//
//  main.cpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/19/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "/usr/local/include/eigen3/Eigen/Dense"
#include "filter.hpp"
#include "tracking.hpp"
#include <vector>
#include <string>
#include <typeinfo>

using namespace Eigen;

std::vector<std::vector<int>> File(std::string file_path){
    std::ifstream myfile(file_path);
    std::vector<std::vector<int>> path( 100, std::vector<int> (2,0));
    
    if (myfile)
    {
        std::string line;
        int counter = 0;
        while (getline(myfile, line))
        {
            int i,j;
            char k;
            std::istringstream(line) >>i>>k>>j;

            //std::cout << typeid(line).name() << std::endl;
            path[counter][0] = i;//line[0];
            path[counter][1] = j;
            ++counter;
        }
        path.resize(counter);
        std::cout<<counter<<std::endl;
    }
    myfile.close();
    
    return path;
    
    
}



int main() {
    
    std::cout<<"Getting sensor readings"<<std::endl;
    std::vector<std::vector<int>> path;
    
    path = File("/Users/gautamsharma/Desktop/SDCN/Kalman Filter/Kalman Filter/path.txt");
     
    size_t size = path.size();
    std::cout<<"Size of sensor readings : "<<size<<std::endl;
    
    Filter filter; //Initializing Kalman filter used for prediction
    Update update;// Initializing Update Class used for measurement update
    
    for (int i=0; i < size-1 ; i++){
   
//
            VectorXd x =  filter.state();
            //std::cout<< x<<std::endl;
            MatrixXd P =  filter.state_covariance();
            //std::cout<< P<<std::endl;

            filter.Prediction(x);
//
            VectorXd z = VectorXd(2);
        
          std::cout<<"X coordinate:"<<path[i][0]<<"Ycoordinate:"<<path[i][1]<<std::endl;
            z<<path[i][0],path[i][1];
        
            update.Measurement(z, filter);

   }
   
    return 0;
     
                
}
