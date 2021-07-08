#include "PiController.h"
#include "stdlib.h"

double seriesPi(struct Controller_t *this, double setPoint, double measurement, double min, double max)
{
	double err = setPoint - measurement;

	this->prop.coef.pid.outPut = this->prop.coef.pid.outPut + this->prop.coef.pid.kp * (1 + this->prop.coef.pid.ki) * err -
			this->prop.coef.pid.kp * this->prop.coef.pid.errOld;
	this->prop.coef.pid.outPut = this->prop.coef.pid.outPut > max ? max : this->prop.coef.pid.outPut;
	this->prop.coef.pid.outPut = this->prop.coef.pid.outPut < min ? min : this->prop.coef.pid.outPut;
	this->prop.coef.pid.errOld = err;

	return this->prop.coef.pid.outPut;
}

double parallelPi(struct Controller_t *this, double setPoint, double measurement, double min, double max)
{
	double err = setPoint - measurement;
	this->prop.coef.pid.errSum += err;
	this->prop.coef.pid.outPut = this->prop.coef.pid.kp * err + this->prop.coef.pid.ki * this->prop.coef.pid.errSum;
	this->prop.coef.pid.outPut = this->prop.coef.pid.outPut > max ? max : this->prop.coef.pid.outPut;
	this->prop.coef.pid.outPut = this->prop.coef.pid.outPut < min ? min : this->prop.coef.pid.outPut;

	return this->prop.coef.pid.outPut;
}

Controller_t *getPiController(ControllerProp_t *prop)
{
    Controller_t *controller = malloc(sizeof(Controller_t));
    controller->prop = *prop;
	switch (prop->type) {
	case CTRL_PI_SERIES:
	    controller->controll = seriesPi;
		break;
	case CTRL_PI_PARALLEL:
	    controller->controll = parallelPi;
		break;
	}
	return controller;
}
