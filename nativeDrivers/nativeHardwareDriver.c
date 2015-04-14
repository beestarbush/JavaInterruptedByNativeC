#include "nativeHardwareDriver.h"

void configureIO(int type, int pinToConfigure, int value) {
	if(type == PWM_OUTPUT) {
		softPwmCreate(pinToConfigure, value, 255);
	}
	else if(type == DIGITAL) {
		pinMode(pinToConfigure, value);
	}
}

void setDigitalOutput(int outputPin, int state) {
	if((state == LOW) || (state == HIGH)) {
		digitalWrite(outputPin, state);
	}
}

void setAnalogOutput(int outputPin, int value) {
	if((value >= 0) && (value <= PWMRANGE)) {
		softPwmWrite(outputPin, value);		
	}
}