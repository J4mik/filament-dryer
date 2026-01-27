#include <LiquidCrystal_I2C.h>

#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_IN1 2
#define PIN_IN2 3

#define heater_PIN 5

LiquidCrystal_I2C lcd(0x27, 16, 2);
static unsigned char deg[8] = {
  B00110,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

int tempConversion[136] = {97, 101, 106, 110, 115, 120, 125, 130, 135, 140, 146, 151, 157, 163, 169, 175, 182, 188, 195, 202, 209, 215, 223, 230, 237, 245, 252, 260, 268, 276, 284, 292, 301, 309, 
318, 326, 335, 344, 352, 361, 370, 379, 388, 397, 406, 415, 425, 434, 443, 452, 461, 471, 480, 489, 498, 507, 516, 525, 534, 543, 547, 561, 569, 578, 587, 595, 604, 612, 620, 628, 636, 644, 
652, 660, 667, 675, 682, 690, 697, 704, 711, 718, 725, 731, 738, 744, 750, 757, 762, 768, 774, 780, 786, 791, 796, 801, 807, 812, 817, 821, 826, 831, 835, 840, 844, 848, 852, 856, 860, 864, 
868, 872, 875, 878, 882, 885, 889, 892, 895, 898, 901, 903, 906, 909, 912, 915, 917, 919, 922, 924, 927, 929, 931, 933, 935, 937};
int targetTemp = 50;
int temp;
int tempReading;

bool heater;

int pos = 100;

int Degree = 0x00;

RotaryEncoder *encoder = nullptr;

void checkPosition() {
  encoder->tick(); // just call tick() to check the state.
  pos = encoder->getPosition();
}

void setup() {
  pinMode(heater_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();

  lcd.createChar (0x00, deg);
  lcd.clear();

  encoder = new RotaryEncoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);

  // register interrupt routine
  attachInterrupt(digitalPinToInterrupt(PIN_IN1), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_IN2), checkPosition, CHANGE);
}

void loop() {
  tempReading = analogRead(A2);
  for (int i = 0; i < 136; ++i) {
    if (tempReading < tempConversion[i]) {
      temp = i - 12;
      break;
    }
  }

  targetTemp = 50 - (pos * 0.5);

  lcd.setCursor(0, 0);   

  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.print("/");
  lcd.print(targetTemp);

  lcd.write(Degree);
  lcd.print("C      ");

  lcd.setCursor(0,1);

  if (targetTemp >= temp) {
    lcd.print("Heating...");
    digitalWrite(heater_PIN, LOW);
  }
  else {
    lcd.print("Cooling...");
    digitalWrite(heater_PIN, HIGH);
  }

  for (int i = 0; i < 4; ++i) {
    delay(200);

    targetTemp = 50 - (pos * 0.5);

    lcd.setCursor(6, 0);

    lcd.print(temp);

    lcd.print("/");
    lcd.print(targetTemp);

    lcd.write(Degree);
    lcd.print("C      ");
  }
  delay(200);
}
