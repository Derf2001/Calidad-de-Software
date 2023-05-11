uint8_t Falling_edge(int btn) {
  uint8_t newValue = digitalRead(button[btn]);
  uint8_t result = button_State[btn] != newValue && newValue == 1;  
  button_State[btn] = newValue;
  if (digitalRead(button[btn]) == LOW) {  //Modificar
  }
  if (result == 1) {
    contadorLuz = 0;
  }

  return result;
}

void loopAlarm() {
  if (Falling_edge(BTN_MODO)) {
    Serial.println("LLEGUE!!!");
    actualizar = true;
    if (ScreenState == S_ALARM)
      state++;
    ScreenState = S_ALARM;
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

  if (!digitalRead(button[BTN_UP])) {

    HoldOnFechayHora = false;
  } else {
    HoldOnFechayHora = true;
  }

  if (!digitalRead(button[BTN_DOWN])) {

    HoldOnTemperatura = false;
  } else {
    HoldOnTemperatura = true;
  }

  if (ScreenState == S_ALARM) {
    actualizar = true;
  } else {
    actualizar = false;
    state = S_SET_ALARM_HOUR;
  }
}
