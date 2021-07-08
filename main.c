#include <stdio.h>
#include "PiController.h"

int main() {
  ControllerProp_t prop;
  prop.type = CTRL_PI_SERIES; // or CTRL_PI_PARALLEL
  prop.coef.pid.kp = 0;
  prop.coef.pid.ki = 0;
  prop.coef.pid.errOld = 0;
  prop.coef.pid.errSum = 0;
  prop.coef.pid.outPut = 0;
  Controller_t *piController = getPiController(&prop);
  double setPoint = 0;
  double measurement = 0;
  double max = 0;
  double min = 0;
  double outPut = piController->control(piController, setPoint, measurement, min, max);
  return 0;
}
