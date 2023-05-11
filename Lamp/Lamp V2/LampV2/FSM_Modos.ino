void Efectos();

void FSM_Color() {
  switch (state) {
    case S_HOME:
      if (anterior == S_SEQ) {
        colorWipe(tira.Color(255, 0, 0), 50);  // Rojo
        colorWipe(tira.Color(0, 255, 0), 50);  // Verde
        colorWipe(tira.Color(0, 0, 255), 50);  // Azul
                                               //colorWipe(tira.Color(255, 0, 0), 50);
      } else {
        color_aterior = S_HOME;
        for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 255, 255, 255);
          tira.show();
          delay(retardo);
        }
      }
      break;
    case C_VERDE:
      if (anterior == S_SEQ) {
        rainbow(150);
      } else {
        color_aterior = C_VERDE;
        for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 50, 205, 50);
          tira.show();
          delay(retardo);
        }
      }
      break;
    case C_ROJO:
      if (anterior == S_SEQ) {
        rainbowCycle(20);
      } else {
        color_aterior = C_ROJO;
        for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 255, 0, 0);
          tira.show();
          delay(retardo);
        }
      }
      break;
    case C_AZUL:
      if (anterior == S_SEQ) {
        theaterChase(tira.Color(127, 255, 0), 50);
      } else {
        color_aterior = C_AZUL;
        for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 30, 144, 255);
          tira.show();
          delay(retardo);
        }
      }
      break;
    case OFF:
      tira.clear();
      tira.show();
      break;
    default: break;
  }
}

void FSM_Modo() {
  switch (anterior) {
    case S_OFF:
      anterior = S_SEQ;
      delay(200);
      break;
    case S_SEQ:
      anterior = S_OFF;
      // state = color_aterior;
      delay(200);
      break;
  }
}