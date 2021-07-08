#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Pedestal/common.h"

typedef enum {
	CTRL_PI_SERIES,
	CTRL_PI_PARALLEL,
} ControllerType_t;

typedef struct Pid_t {
    double kp;
    double ki;
    double kd;
    double errOld;
    double errSum;
    double outPut;
} Pid_t;

union ControllerCoef_t {
    struct Pid_t pid;
};

typedef struct {
    ControllerType_t type;
    union ControllerCoef_t coef;
} ControllerProp_t;

typedef struct Controller_t {
	double (*controll)(struct Controller_t *, double, double, double, double);
	ControllerProp_t prop;
} Controller_t;

double control(struct Controller_t *this, double setPoint, double measurement, double min, double max);
Controller_t *getController(ControllerType_t type, ControllerProp_t *prop);

#endif
