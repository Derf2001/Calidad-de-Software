void cambioEstados() {
  switch (state) {
    case S_SET_ALARM_HOUR:
      if (Falling_edge(BTN_UP) && ScreenState == S_ALARM) {
        incrementarHorasAlarm();
      }
      if (Falling_edge(BTN_DOWN) && ScreenState == S_ALARM) {
        decrementarHorasAlarm();
      }
      break;
    case S_SET_ALARM_MINUTES:
      if (Falling_edge(BTN_UP) && ScreenState == S_ALARM) {
        incrementarMinutosAlarm();
      }
      if (Falling_edge(BTN_DOWN) && ScreenState == S_ALARM) {
        decrementarMinutosAlarm();
      }
      break;
    case S_SET_ALARM_ON_OFF:
      if (Falling_edge(BTN_UP)) {
        actualizar = true;

        alarmaOn = !alarmaOn;

        if (alarmaOn) {
          digitalWrite(BUZZER, HIGH);
          delay(100);
          digitalWrite(BUZZER, LOW);
          delay(100);
          digitalWrite(BUZZER, HIGH);
          delay(100);
          digitalWrite(BUZZER, LOW);
          ScreenState = S_DATEHOUR;
          state++;
        } else {
          ScreenState = S_DATEHOUR;
          state++;
        }
      }
      break;
    case S_HOME_ALARM:
      ScreenState = S_DATEHOUR;
      state--;
      break;
  }
}