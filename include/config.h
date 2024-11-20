#ifndef CONFIG_H
#define CONFIG_H

#define LED_PIN 2

extern const unsigned long LED_Delays[3][2];

extern volatile int currentState;
extern unsigned long previousMillis;
extern unsigned long previousMillisLED;
extern const long interval;
extern unsigned long lastSwitchTime;

#endif
