#include <Adafruit_NeoPixel.h>
int nleds = 4;
int pinled = 12;
int retardo = 150;
int brillo = 50;

//#define BTN 0
int pinBtn1 = 8;
int pinBtn2 = 7;
int pinBtn3 = 6;
int pinBtn4 = 5;
int contador = 0;

#define S_HOME 0
#define C_VERDE 1
#define C_ROJO 2
#define C_AZUL 3
#define C_OFF 4

uint8_t state = S_HOME;
void Control_Management();

Adafruit_NeoPixel tira = Adafruit_NeoPixel(nleds, pinled, NEO_RGB + NEO_KHZ800);

void setup() {
  pinMode(pinBtn1, INPUT_PULLUP);
  pinMode(pinBtn2, INPUT_PULLUP);
  pinMode(pinBtn3, INPUT_PULLUP);
  pinMode(pinBtn4, INPUT_PULLUP);
  tira.begin();
  tira.show();
  Serial.begin(9600);
}

void loop() {
  tira.setBrightness(brillo);
  Control();
  casosLeds();
}

void casosLeds() {
  switch (state) {
    case S_HOME:
      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, 255, 255, 255);
        tira.show();
      }
      delay(retardo);
      break;
    case C_VERDE:
      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, 50, 205, 50);
        tira.show();
      }
      delay(retardo);
      break;
    case C_ROJO:
      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, 255, 0, 0);
        tira.show();
      }
      delay(retardo);
      break;
    case C_AZUL:
      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, 30, 144, 255);
        tira.show();
      }
      delay(retardo);
      break;
      case C_OFF:
      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, 0, 0, 0);
        tira.show();
      }
      delay(retardo);
      break;
  }
}
