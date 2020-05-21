//
//  tracking.cpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/19/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//
#include <iostream>
#include "tracking.hpp"
#include "filter.hpp"
#include <vector>
#include "/usr/local/include/eigen3/Eigen/Dense"

void Update::Measurement( VectorXd &z, Filter &f){
    
    //Measurement Update
     VectorXd z_pred = f.H_ * f.x_;
     VectorXd y_ = z - z_pred;
     MatrixXd Ht = f.H_.transpose();
     MatrixXd S = f.H_ * f.P_ * Ht + f.R_;
     MatrixXd Si = S.inverse();
     MatrixXd PHt = f.P_ * Ht;
     MatrixXd K = PHt * Si;

     //new estimate
    f.x_ = f.x_ + (K * y_);
    f.P_ = (Update::I_ - K * f.H_) * f.P_;
    
    std::cout<<"x: "<<f.x_<<std::endl;
}
