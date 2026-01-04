const int ledPin = PC13; // Pin connected to the LED (PWM pin)

void setup() {
    pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
}

void loop() {
    // Increase brightness
    for (int brightness = 0; brightness <= 2550; brightness++) {
        analogWrite(ledPin, brightness);
        delay(10);
    }
}
