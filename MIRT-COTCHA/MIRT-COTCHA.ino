// Improved LED Control with MIRT Mode
const int SWITCH_PIN = 13;
const int LED_ARRAY = 2;  // Changed from 0 to avoid conflict with serial communication
const int LED_R = 3;
const int LED_G = 5;
const int LED_B = 6;

int counter = 0;
const int MAX_MODE = 7;

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  pinMode(LED_ARRAY, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  Serial.begin(9600);  // For debugging
}

void loop() {
  // Handle input
  int switchVal = digitalRead(SWITCH_PIN);
  if (switchVal == HIGH) {
    delay(500);  // Debounce delay
    counter = (counter + 1) % (MAX_MODE + 1);  // Increment and wrap around
    Serial.print("Mode changed to: ");
    Serial.println(counter);
  }

  // Change mode
  switch (counter) {
    case 0:
      setAllLEDs(0, 0, 0);  // All LEDs off
      break;
    case 1:
      setAllLEDs(255, 0, 0);  // Full red
      break;
    case 2:
      setAllLEDs(127, 0, 0);  // Half red
      break;
    case 3:
      setAllLEDs(0, 0, 255);  // Full blue
      break;
    case 4:
      setAllLEDs(0, 0, 127);  // Half blue
      break;
    case 5:
      setAllLEDs(255, 255, 255);  // Full white
      break;
    case 6:
      setAllLEDs(127, 127, 127);  // Half white
      break;
    case 7:
      mirtMode();  // MIRT (Mobile Infrared Transmitter) mode
      break;
  }
}

void setAllLEDs(int r, int g, int b) {
  analogWrite(LED_R, r);
  analogWrite(LED_G, g);
  analogWrite(LED_B, b);
  digitalWrite(LED_ARRAY, LOW);  // Turn off LED array in non-MIRT modes
}

void mirtMode() {
  setAllLEDs(0, 0, 0);  // Ensure RGB LEDs are off during MIRT mode
  digitalWrite(LED_ARRAY, HIGH);
  delay(35);
  delayMicroseconds(544);
  digitalWrite(LED_ARRAY, LOW);
  delay(35);
  delayMicroseconds(552);
}
