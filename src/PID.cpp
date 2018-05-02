#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0.0;
  	i_error = 0.0;
  	d_error = 0.0;
  	step = 1;
  	minError = std::numeric_limits<double>::max();
  	maxError = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {

	if(step == 1)
		p_error = cte;

    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;


    if ( cte > maxError ) {
    	maxError = cte;
 	}
  	if ( cte < minError ) {
    	minError = cte;
  	}
	++step;	
}

double PID::TotalError() {	
	return Kp * p_error + Kd * d_error + Ki * i_error;
}

