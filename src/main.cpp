#include <Arduino.h>  // Inclure le framework Arduino pour utiliser les fonctions de base comme pinMode, digitalWrite, etc.

#define LED_PIN 2
#define DELAY_ON_A 500
#define DELAY_OFF_A 500
#define DELAY_ON_B 50
#define DELAY_OFF_B 50
#define DELAY_ON_C 10
#define DELAY_OFF_C 10

volatile int currentState = 0;  
unsigned long previousMillis = 0;
const long interval = 30000;  

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        currentState = (currentState + 1) % 3;
    }

    switch (currentState) {
        case 0:
            digitalWrite(LED_PIN, HIGH);
            printf("LED A ON\n");
            delay(DELAY_ON_A);
            digitalWrite(LED_PIN, LOW);
            printf("LED A OFF\n");
            delay(DELAY_OFF_A);
            break;

        case 1:
            digitalWrite(LED_PIN, HIGH);
            printf("LED B ON\n");
            delay(DELAY_ON_B);
            digitalWrite(LED_PIN, LOW);
            printf("LED B OFF\n");
            delay(DELAY_OFF_B);
            break;

        case 2:
            digitalWrite(LED_PIN, HIGH);
            printf("LED C ON\n");
            delay(DELAY_ON_C);
            digitalWrite(LED_PIN, LOW);
            printf("LED C OFF\n");
            delay(DELAY_OFF_C);
            break;
    }
}