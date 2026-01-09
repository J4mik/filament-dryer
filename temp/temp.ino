int tempConversion[136] = {97, 101, 106, 110, 115, 120, 125, 130, 135, 140, 146, 151, 157, 163, 169, 175, 182, 188, 195, 202, 209, 215, 223, 230, 237, 245, 252, 260, 268, 276, 284, 292, 301, 309, 
318, 326, 335, 344, 352, 361, 370, 379, 388, 397, 406, 415, 425, 434, 443, 452, 461, 471, 480, 489, 498, 507, 516, 525, 534, 543, 547, 561, 569, 578, 587, 595, 604, 612, 620, 628, 636, 644, 
652, 660, 667, 675, 682, 690, 697, 704, 711, 718, 725, 731, 738, 744, 750, 757, 762, 768, 774, 780, 786, 791, 796, 801, 807, 812, 817, 821, 826, 831, 835, 840, 844, 848, 852, 856, 860, 864, 
868, 872, 875, 878, 882, 885, 889, 892, 895, 898, 901, 903, 906, 909, 912, 915, 917, 919, 922, 924, 927, 929, 931, 933, 935, 937};
int analogReading;
int targetTemp = 50;
int ofset = -12;

const int heater = 2;

void setup() {
  Serial.begin(9600);
  pinMode(heater, OUTPUT);
}

void loop() {
  analogReading = analogRead(A2);
  for (int i = 0; i < 136; ++i) {
    if (analogReading < tempConversion[i]) {
      if (i + ofset < targetTemp) {
        digitalWrite(heater, LOW);
      }
      else {
        digitalWrite(heater, HIGH);
      }
      Serial.print(i + ofset);
      Serial.println("°C");
      break;
    }
  }
  delay(1000);
}

// 42°C with back insulation (15min warmup time)
// 48°C with back & top insulation (15min warmup time)
// 52°C with back & top insulation with power supply heat recerculation (15min warmup time)
// 77°C with all previous and blaket (1h warmup time)