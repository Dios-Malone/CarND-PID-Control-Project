#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double MaxIn) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // initiate controller parameters
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;

  // set initial errors to zero
  p_error = 0;
  i_error = 0;
  d_error = 0;

  // initiate I-maximum
  Max = MaxIn;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // update error parts
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
  // limit I-error
  if(i_error > Max) i_error = Max;
  else if(i_error < (-Max)) i_error = (-Max);

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // calculate controller output
  double total_error = (Kp * p_error + Ki * i_error + Kd * d_error);
  std::cout << "p_Term: " << Kp * p_error << " i_Term: " << Ki * i_error << " d_Term: " << Kd * d_error << " TotalError: " << total_error << std::endl;
  return total_error;
}