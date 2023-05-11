#include <Adafruit_NeoPixel.h>
#include <IRremote.h>

#define S_HOME 0
#define C_VERDE 1
#define C_ROJO 2
#define C_AZUL 3
#define S_SEQ 4
#define S_OFF 5
#define OFF 6
#define STATE_MAX 7

int segundos = 0;
uint8_t state = OFF;
int PIRPin = 13;

int nleds = 4;
int pinled = 12;
int retardo = 50;
int brillo = 50;
int BTN_MODO = 8;
int anterior = S_OFF;
int color_aterior = 0;

bool buttonState = false;
unsigned long lastButtonPressTime = 0;
unsigned long lastButtonPress = 0;

const int irReceivePin = 5;
unsigned long codigo = 0xCF200;

IRrecv irrecv(irReceivePin);
decode_results results;

Adafruit_NeoPixel tira = Adafruit_NeoPixel(nleds, pinled, NEO_RGB + NEO_KHZ800);

void FSM_Modos();
void FSM_Control();

void setup() {
  pinMode(BTN_MODO, INPUT);
  pinMode(PIRPin, INPUT);
  irrecv.enableIRIn();
  tira.begin();
  tira.show();
  Serial.begin(9600);
}

void loop() {
  tira.setBrightness(brillo);
  BTN_Control();
  FSM_Color();
  SensorIR();
  SensorPIR();
 // theaterChaseRainbow(500);
}


