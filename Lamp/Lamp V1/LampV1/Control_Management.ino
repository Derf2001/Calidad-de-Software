void Control() {
  
  if (digitalRead(pinBtn4) == HIGH) {
    state = C_ROJO;
    contador = 0;
  }
  if (digitalRead(pinBtn1) == HIGH) {
    state = S_HOME;

    contador = 0;
  }
  if (digitalRead(pinBtn2) == HIGH) {

    state = C_VERDE;
    contador = 0;
  }
  if (digitalRead(pinBtn3) == HIGH) {
    state = C_AZUL;
    contador = 0;
  } else {
    contador++;
    Serial.println(contador);
  }

  if (contador == 60) {
    state = C_OFF;
    contador = 0;
  }
}