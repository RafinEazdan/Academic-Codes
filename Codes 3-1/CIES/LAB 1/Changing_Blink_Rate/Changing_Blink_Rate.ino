void setup() {
    // Initialize the LED pin as an output
    pinMode(PC13, OUTPUT);
}

void loop() {
    static int delayTime = 100; // Initial delay in milliseconds

    // Toggle the LED state
    digitalWrite(PC13, !digitalRead(PC13));
    
    // Wait for the delay time
    delay(delayTime);

    // Change the delay to create a changing blink rate
    delayTime += 100;
    if (delayTime > 1000) {
        delayTime = 100; // Reset delay after reaching 1000 ms
    }
}
