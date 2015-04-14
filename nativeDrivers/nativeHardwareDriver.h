#include <wiringPi.h>
#include <softPwm.h>

#define DIGITAL				0
#define PWMRANGE			255

void configureIO(int type, int pinToConfigure, int value); 
void setDigitalOutput(int outputPin, int state);
void setAnalogOutput(int outputPin, int value);