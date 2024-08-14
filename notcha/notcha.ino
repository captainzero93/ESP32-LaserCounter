// NOTCHA-COTCHA CODE - 2024 Update

#include <Wire.h>
#include <LOLIN_I2C_BUTTON.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int BUFFDSIZE = 200;
char message[BUFFDSIZE];

const int LIDAR_EMITTER = 13;
const int TRIGGER_BUTTON = 11;
const int CHANGE_MODE_BUTTON = 12;

int displayLength, minX;
int pulse = 1;  // pulse size length in microseconds
int choice = 0;  // select laser gun model type
int lastChoice = 0;  // recall last selection choice
bool changeModeButtonPressed = false;
bool triggerPressed = false;

struct LaserModel {
  const char* name;
  int pulsesPerSecond;
  int burstCount;
  bool stealthMode;
};

const LaserModel LASER_MODELS[] = {
  {"Ultralyte Non-LR", 100, 3, false},
  {"Ultralyte Rev.1", 100, 3, false},
  {"Jenoptik LaserPL", 100, 3, false},
  {"Kustom Prolaser3", 200, 3, false},
  {"Jenoptik Laveg", 600, 3, false},
  {"Kustom Prolaser1", 380, 3, false},
  {"Ultralyte Rev.2", 125, 3, false},
  {"Stalker LZ-1", 130, 3, false},
  {"Kustom Prolaser2", 238, 3, false},
  {"Laser Atlanta", 238, 3, false},
  {"Laser Atlanta Stealth", 238, 2, true},
  {"Kustom ProLite", 200, 3, false}
};

const int NUM_MODELS = sizeof(LASER_MODELS) / sizeof(LASER_MODELS[0]);

void setup() {
  Serial.begin(115200);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);  // Don't proceed, loop forever
  }

  pinMode(LIDAR_EMITTER, OUTPUT);
  pinMode(CHANGE_MODE_BUTTON, INPUT_PULLUP);
  pinMode(TRIGGER_BUTTON, INPUT_PULLUP);

  setLaserName("Power On");
  displayLength = display.width();
  minX = -12 * strlen(message);
  displayData();

  Serial.println("NOTCHA-COTCHA initialized");
}

void loop() {
  handleModeChange();
  handleTrigger();
  updateDisplay();
}

void handleModeChange() {
  if (digitalRead(CHANGE_MODE_BUTTON) == HIGH) {
    changeModeButtonPressed = false;
  }
  if (digitalRead(CHANGE_MODE_BUTTON) == LOW && !changeModeButtonPressed) {
    choice = (choice + 1) % NUM_MODELS;
    changeModeButtonPressed = true;
    Serial.print("Selected mode: ");
    Serial.println(LASER_MODELS[choice].name);
  }

  if (choice != lastChoice) {
    displayLength = display.width();
    lastChoice = choice;
  }
}

void handleTrigger() {
  triggerPressed = (digitalRead(TRIGGER_BUTTON) == LOW);
  if (triggerPressed) {
    Serial.print("Fired: ");
    Serial.println(LASER_MODELS[choice].name);
    fireLaser();
  }
}

void fireLaser() {
  const LaserModel& model = LASER_MODELS[choice];
  int delayBetweenPulses = 1000000 / model.pulsesPerSecond - pulse;

  for (int i = 0; i < model.burstCount; i++) {
    digitalWrite(LIDAR_EMITTER, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(LIDAR_EMITTER, LOW);
    
    if (model.stealthMode && i == 1) {
      delayMicroseconds(delayBetweenPulses * 6);
    } else {
      delayMicroseconds(delayBetweenPulses);
    }
  }
}

void setLaserName(const char* name) {
  strncpy(message, name, BUFFDSIZE - 1);
  message[BUFFDSIZE - 1] = '\0';
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);
  display.setCursor(displayLength, 0);
  display.println(LASER_MODELS[choice].name);

  if (triggerPressed) {
    display.setTextSize(1);
    display.println("      ...FIRE...");
  }

  display.display();

  if (--displayLength < minX) displayLength = display.width();
}
