//
//  filter.cpp
//  Kalman Filter
//
//  Created by Gautam Sharma on 5/19/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#include "filter.hpp"
#include <iostream>
#include "/usr/local/include/eigen3/Eigen/Dense"
using Eigen::MatrixXd;
using Eigen::VectorXd;

Filter::Filter(){
    
    //Filter::x_<<1,1,1,1; //state vector initialization
     x_ = VectorXd(4);
     P_ = MatrixXd(4,4);
     F_ = MatrixXd(4,4);
     H_ = MatrixXd(2,4);
     Q_ = MatrixXd(4,4);
     R_ = MatrixXd(2,2);
    x_ << 0,0,0,0;
    P_<< 1, 0, 0, 0, //state covariance matrix
           0, 1, 0, 0,
           0, 0, 10, 0,
           0, 0, 0, 10;

    F_<<1,0,1,0,  // transition matrix F_
                0,1,0,1,
                0,0,1,0,
                0,0,0,1;
    
    H_<<1,0,0,0,
        0,1,0,0;
    
    Q_<<0,0,0,0, //Process noise assumed to be 0
                0,0,0,0,
                0,0,0,0,
                0,0,0,0;
    
    R_<< 0.0225, 0, //measurement covariance matrix
                0, 0.0225;
    
std::cout<<"-----------Kalman filter initialised---------"<<std::endl;
}
Filter::~Filter(){}
void Filter::Prediction( VectorXd x){
    
    // Prediction Step of Kalman Filter

     this->x_(0) = x(0);//state vector initialization
     this->x_(1) = x(1);
     this->x_(2) = x(2);
     this->x_(3) = x(3);

    this->x_ = this->F_*this->x_; //State vector update
    

    MatrixXd Ft = MatrixXd(4,4);
    Ft = this->F_.transpose();//transpose of Ft
    //std::cout<<"Ft"<<Ft<<std::endl;

    this->P_ = this->F_*this->P_*Ft + this->Q_; //state covariance matrix
    
    
    std::cout<<"x: "<< this->x_ <<std::endl;
}

VectorXd Filter::state(){
       
    return this->x_;
   }

MatrixXd Filter::state_covariance(){
       
    return this->P_;
   }
