void cambioEstados() {
  switch (state) {

    case S_SET_CLOCK_HOUR:
      if (Falling_edge(BTN_UP)) {
        incrementarHoras();
      }
      if (Falling_edge(BTN_DOWN)) {
        decrementarHoras();
      }
      break;
    case S_SET_CLOCK_MINUTES:
      if (Falling_edge(BTN_UP)) {
        incrementarMinutos();
      }
      if (Falling_edge(BTN_DOWN)) {
        decrementarMinutos();
      }
      break;
    case S_SET_ALARM_HOUR:
      if (Falling_edge(BTN_UP)) {
        incrementarHorasAlarm();
      }
      if (Falling_edge(BTN_DOWN)) {
        decrementarHorasAlarm();
      }
      break;
    case S_SET_ALARM_MINUTES:
      if (Falling_edge(BTN_UP)) {
        incrementarMinutosAlarm();
      }
      if (Falling_edge(BTN_DOWN)) {
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
        }
      }
      break;
  }
}