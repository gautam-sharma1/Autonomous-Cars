//
//  io.cpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/23/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "/usr/local/include/eigen3/Eigen/Dense"
#include <fstream>
#include "io.hpp"
using namespace Eigen;

std::vector<std::vector<int>> File(std::string file_path){
    std::ifstream myfile(file_path);
    std::vector<std::vector<int>> path( 100, std::vector<int> (2,0)); //Initializing the vector that will hold the sensor values
    
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
        std::cout<<counter<<"\n";
    }
    myfile.close();
    return path;
    
}

void SaveFile(std::string file, std::vector<VectorXd> pos){
    std::ofstream f(file);
    if(f){
        for(const VectorXd &v : pos){
             f<<v(0)<<","<<v(1)<<'\n';
            
        }
        std::cout<<"Files saved successfullly"<<std::endl;
    }
    else{
        std::cerr<<"File cannot be found!"<<std::endl;
    }
}
