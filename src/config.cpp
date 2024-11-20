#include "config.h"

const unsigned long LED_Delays[3][2] = {
    {500, 500}, // LED A
    {50, 50},   // LED B
    {10, 10}    // LED C
};

volatile int currentState = 0;
unsigned long previousMillis = 0;
unsigned long previousMillisLED = 0; 
const long interval = 30000;  
unsigned long lastSwitchTime = 0; 
