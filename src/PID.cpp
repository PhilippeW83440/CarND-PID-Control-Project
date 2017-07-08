#include "PID.h"
#include <ctime>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  i_error = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Kd = Kd;
  this->Ki = Ki;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  double steer = -Kp * p_error -Kd * d_error -Ki * i_error;

  steer = steer >  1 ?  1 : steer;
  steer = steer < -1 ? -1 : steer;

  return steer;
}
