#include <Arduino.h>  
#define LED_PIN 2

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
void handleLED(int state, unsigned long currentMillis);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();

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
