//
//  io.hpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/23/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#ifndef io_h
#define io_h
#include <iostream>
#include <vector>
#include <string>
#include "/usr/local/include/eigen3/Eigen/Dense"
#include <fstream>
using namespace Eigen;

std::vector<std::vector<int>> File(std::string file_path);
void SaveFile(std::string file, std::vector<VectorXd> pos);

#endif /* io_h */
