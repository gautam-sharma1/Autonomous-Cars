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
#include "io.hpp"

using namespace Eigen;


template <typename T>
T myVector(int size)
{
    return T(2);
}
//Function to read in the sensor readings

size_t MAX_READINGS = 20;

int main() {
    
    std::cout<<"Getting sensor readings"<<std::endl;
    std::vector<std::vector<int>> path; //Sensor readings defined
    
    std::string output = "/Users/gautamsharma/Desktop/SDCN/Kalman Filter/Kalman Filter/output.txt";
    
    path = File("/Users/gautamsharma/Desktop/SDCN/Kalman Filter/Kalman Filter/path.txt");
     
    size_t size = path.size();
    std::cout<<"Size of sensor readings : "<<size<<std::endl;
    
    VectorXd x_p = myVector<VectorXd>(2); //temperory vector
    x_p<<0,0;
    std::vector<VectorXd> pos{MAX_READINGS,x_p}; //x and y position predicted by the filter
    
    Filter filter; //Initializing Kalman filter used for prediction
    Update update;// Initializing Update Class used for measurement update
    
    for (int i=0; i < size-1 ; i++){
   
            VectorXd x =  filter.state();//Get the current state
            VectorXd x_pos = VectorXd(2);
            x_pos << x(0),x(1);
            pos[i] = x_pos;

            MatrixXd P =  filter.state_covariance();//get the current state covariance
    
            filter.Prediction(x);//Prediction Step

            VectorXd z = VectorXd(2);
        
          // std::cout<<"X coordinate:"<<path[i][0]<<"Ycoordinate:"<<path[i][1]<<std::endl;
            z<<path[i][0],path[i][1];//Get the predicted sensor readings
        
            update.Measurement(z, filter);//Do a measurement update step

    }
    std::cout<<pos.size()<<std::endl;
    SaveFile(output, pos); //Save the estimated values
   
    return 0;
}

