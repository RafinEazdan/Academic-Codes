const int LED = PC13;
// The LED is connected to pin 9
const int BUTTON = PC15;
// The Button is connected to pin 2
void setup() {
  pinMode(LED, OUTPUT);
  // Set the LED pin as an output
  pinMode(BUTTON, INPUT);
  // Set button as input (not required)
}
void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
}