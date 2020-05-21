//
//  tracking.hpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/19/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#ifndef tracking_hpp
#define tracking_hpp

#include <stdio.h>
#include "filter.hpp"
#include "/usr/local/include/eigen3/Eigen/Dense"
using namespace Eigen;

class Update{
    
private:
    VectorXd y_ = VectorXd(4); //output vector
    MatrixXd I_ = MatrixXd::Identity(4,4);

public:
    
    void Measurement(VectorXd &z, Filter &f);
   
    
};


#endif /* tracking_hpp */
