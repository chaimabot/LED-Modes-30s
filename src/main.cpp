#include <Arduino.h>
#include "config.h"

void handleLED(int state, unsigned long currentMillis);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();

    // Changer d'état toutes les 30 secondes
    if (currentMillis - lastSwitchTime >= interval) {
        lastSwitchTime = currentMillis;
        currentState = (currentState + 1) % 3;
    }

    handleLED(currentState, currentMillis);
}

void handleLED(int state, unsigned long currentMillis) {
    unsigned long delayOn = LED_Delays[state][0];
    unsigned long delayOff = LED_Delays[state][1];

    if (currentMillis - previousMillisLED >= delayOn) {
        digitalWrite(LED_PIN, LOW);
        previousMillisLED = currentMillis;
        Serial.print("LED ");
        Serial.print((char)('A' + state)); 
        Serial.println(" OFF");
    } else {
        digitalWrite(LED_PIN, HIGH);
        Serial.print("LED ");
        Serial.print((char)('A' + state)); 
        Serial.println(" ON");
    }
}
