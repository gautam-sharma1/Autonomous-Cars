//
//  filter.hpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/19/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#ifndef filter_hpp
#define filter_hpp

#include <stdio.h>
#include "/usr/local/include/eigen3/Eigen/Dense"
using namespace Eigen;

class Filter{
    
private:
     VectorXd x_;
     MatrixXd P_ ;
     MatrixXd F_ ;
     MatrixXd H_ ;
     MatrixXd Q_ ;
     MatrixXd R_ ;
    
    
public:
    Filter();
    ~Filter();
    void Prediction(VectorXd x);
    VectorXd state();
    
    MatrixXd state_covariance();
    friend class Update;
};

#endif /* filter_hpp */
