#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <DHT.h>

#define S_HOME 0
#define S_REFRESH 1
#define S_READSENSORS 2
#define S_FSM_SCREEN 3

#define S_WELCOME 0
#define S_DATEHOUR 1
#define S_HUMTEMP 2

#define DHTPin 19
#define DHTType DHT11

char _bufferFecha[12];
char _bufferHora[10];
DateTime now;
DateTime now2;
int hum;
int temp;
int tempC;
char symbol = 223;
int ScreenState = S_WELCOME;
int SystemState = S_HOME;
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
DHT dht11(DHTPin, DHTType);

unsigned long previousMillisSA = 0;
long timeInterval_A = 1000;
unsigned long previuosMillisSB = 0;
long timeInterval_B = 1000;
unsigned long previuosMillisSC = 0;
long timeInterval_C = 3000;

void Control_System_Management();
void Screen_Magement();
void Sensor_Managent();

void setup() {
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("Prueba V2");
  delay(500);
}

void loop() {
  FSM_Transitions();
  FSM_System();
}
