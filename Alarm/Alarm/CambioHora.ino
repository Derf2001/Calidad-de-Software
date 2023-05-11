void configurarHora() {
  if (actualizar == true) {
    formatTime();
    estadoAlarma();
    fijarCursorModo();
  }
}
void fijarCursorModo() {

  switch (state) {
    case S_HOME:
      lcd.noBlink();
      lcd.setCursor(11, 0);
      lcd.print(contadorLuz);
      delay(100);
      break;
    case S_SET_CLOCK_HOUR:
      lcd.setCursor(1, 0);
      lcd.blink();
      delay(100);
      break;
    case S_SET_CLOCK_MINUTES:
      lcd.setCursor(4, 0);  //no es (4,0)??
      lcd.blink();
      delay(100);
      break;
    case S_SET_ALARM_HOUR:
      lcd.setCursor(1, 1);
      lcd.blink();
      delay(100);
      break;
    case S_SET_ALARM_MINUTES:
      lcd.setCursor(4, 1);
      lcd.blink();
      delay(100);
      break;
    case S_SET_ALARM_ON_OFF:
      lcd.setCursor(7, 1);
      lcd.blink();
      delay(100);

      break;
  }
}


void formatTime() {

  minutos += segundos / 60;
  segundos = segundos % 60;
  horas += minutos / 60;
  minutos = minutos % 60;
  horas = horas % 24;
  lcd.clear();
  lcd.noBlink();
  lcd.setCursor(0, 0);

  sprintf(star_time, "%02d:%02d:%02d", horas, minutos, segundos);
  lcd.print(star_time);

  lcd.setCursor(0, 1);
  sprintf(star_time, "%02d:%02d", horas_alarma, minutos_alarma);
  lcd.print(star_time);

  actualizar = false;
}

void estadoAlarma() {
  if (alarmaOn == true) {
    if (segundos == 0 && horas == horas_alarma && minutos == minutos_alarma) {
      digitalWrite(BUZZER, HIGH);
    }
    lcd.print(" On");
  } else {
    lcd.print(" OFF");
  }

  if (contadorAlarma == 5) {
    digitalWrite(BUZZER, LOW);
    contadorAlarma = 0;
  }
  if (contadorLuz == 30) {
    lcd.noBacklight();
    lightOn = false;
    contadorLuz = 0;
  }
}