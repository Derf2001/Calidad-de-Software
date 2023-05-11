#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <DHT.h>
#include <TimerOne.h>

#define S_HOME_WS 0
#define S_REFRESH 1
#define S_READSENSORS 2
#define S_FSM_SCREEN 3
#define S_WELCOME 0
#define S_DATEHOUR 1
#define S_HUMTEMP 2
#define S_ALARM 3
#define DHTPin 19
#define DHTType DHT11

int buttonStateUP = 0;
int buttonState2 = 0;

char _bufferFecha[12];
char _bufferHora[10];
DateTime now;
DateTime now2;
int hum;
int temp;
int tempC;
char symbol = 223;
int ScreenState = S_WELCOME;
int SystemState = S_HOME_WS;
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

//Alarma
#define BTN_MODO 0
#define BTN_UP 1
#define BTN_DOWN 2
#define BTN_LIGHT 3

uint8_t button[4] = {
  10, 9, 8, 7
};

#define BUZZER 12

#define S_HOME_ALARM 0
#define S_SET_ALARM_HOUR 1
#define S_SET_ALARM_MINUTES 2
#define S_SET_ALARM_ON_OFF 3
#define STATE_MAX 4

uint8_t state = S_SET_ALARM_HOUR;
uint8_t button_State[4];

int horas = 0;
int minutos = 0;
int segundos = 0;
int horas_alarma = 0;
int minutos_alarma = 0;
bool alarmaOn = false;
bool lightOn = true;
bool actualizar = false;
int contadorLuz = 0;
int contadorAlarma = 0;
bool HoldOnFechayHora = false;
bool HoldOnTemperatura = false;
char star_time[10];

void falling_button();
void Incrementar_Decrementar();
void comprobarBotones();
void CambioHora();

bool stateAlarm = false;

bool d = false;
bool banderaConfigurarHora = false;

void setup() {

  //Alarma
  pinMode(button[BTN_MODO], INPUT_PULLUP);
  pinMode(button[BTN_UP], INPUT_PULLUP);
  pinMode(button[BTN_DOWN], INPUT_PULLUP);
  pinMode(button[BTN_LIGHT], INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  button_State[0] = HIGH;
  button_State[1] = HIGH;
  button_State[2] = HIGH;
  button_State[3] = HIGH;

  Timer1.initialize(1000000);  //DataShelt, Timer on Arduino Mega
  Timer1.attachInterrupt(ControladorTimer);

  //Estacion
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

  if (HoldOnFechayHora) {
    cleanScreen();
    ScreenState = S_DATEHOUR;
    sensorDate();
    sensorHour();
    RefreshScreen();
    delay(300);
  }

  if (HoldOnTemperatura) {
    cleanScreen();
    ScreenState = S_HUMTEMP;
    displayHum();
    displayTemperaturaRTC();
    RefreshScreen();
    delay(300);
  }

  loopAlarm();
  sonarAlarma();
  luzconter();
}
