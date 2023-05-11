#include <TimerOne.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BTN_MODO 0
#define BTN_UP 1
#define BTN_DOWN 2
#define BTN_LIGHT 3

uint8_t button[4] = {
  10, 9, 8, 7
};

#define BUZZER 12

#define S_HOME 0
#define S_SET_CLOCK_HOUR 1
#define S_SET_CLOCK_MINUTES 2
#define S_SET_ALARM_HOUR 3
#define S_SET_ALARM_MINUTES 4
#define S_SET_ALARM_ON_OFF 5
#define STATE_MAX 6

uint8_t state = S_HOME;
uint8_t button_State[4];
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
char star_time[9] = "00:00:00";

void falling_button();
void Incrementar_Decrementar();
void comprobarBotones();
void CambioHora();

void setup() {
  // put your setup code here, to run once:
  pinMode(button[BTN_MODO], INPUT_PULLUP);
  pinMode(button[BTN_UP], INPUT_PULLUP);
  pinMode(button[BTN_DOWN], INPUT_PULLUP);
  pinMode(button[BTN_LIGHT], INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  button_State[0] = HIGH;
  button_State[1] = HIGH;
  button_State[2] = HIGH;
  button_State[3] = HIGH;

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Prueba Botones");
  delay(500);
  Timer1.initialize(1000000);                //DataShelt, Timer on Arduino Mega
  Timer1.attachInterrupt(ControladorTimer);  //Interrupcion por Timer1
}

void loop() {
  if (Falling_edge(BTN_MODO)) {
    state++;
    state = state % STATE_MAX;
    fijarCursorModo();
  }

  cambioEstados();

  configurarHora();

  if (Falling_edge(BTN_LIGHT)) {
    if (lightOn == false) {
      lcd.backlight();
      contadorLuz = 0;

    } else {
      lcd.noBacklight();
    }
    lightOn = !lightOn;

    if (digitalRead(BUZZER) == HIGH) {
      digitalWrite(BUZZER, LOW);
      contadorAlarma = 0;
    }
  }
}



void ControladorTimer() {
  segundos++;
  if (lightOn == true) {
    contadorLuz++;
  }
  if (digitalRead(BUZZER) == HIGH) {
    contadorAlarma++;
  }
  actualizar = true;
}
