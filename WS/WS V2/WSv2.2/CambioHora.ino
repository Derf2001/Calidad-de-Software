void configurarHora() {
  if (actualizar == true) {
    formatTime();
    estadoAlarma();
    fijarCursorModo();
  }
}
void fijarCursorModo() {

  switch (state) {
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
  lcd.clear();
  lcd.noBlink();
  lcd.setCursor(0, 0);

  horas = now.hour();
  minutos = now.minute();
  segundos = now.second();
  sprintf(star_time, "%02d:%02d:%02d", horas, minutos, segundos);
  lcd.print(star_time);
  lcd.setCursor(0, 1);
  sprintf(star_time, "%02d:%02d", horas_alarma, minutos_alarma);
  lcd.print(star_time);

  actualizar = false;
}

void estadoAlarma() {
  if (alarmaOn == true) {
    Serial.print("Alarma Activada");
    sonarAlarma();
    lcd.print(" On");
  } else {
    lcd.print(" OFF");
  }

  if (contadorAlarma == 5) {
    digitalWrite(BUZZER, LOW);
    contadorAlarma = 0;
  }
  luzconter();
}

void sonarAlarma() {
  if (segundos == 0 && horas == horas_alarma && minutos == minutos_alarma) {
      digitalWrite(BUZZER, HIGH);
      
    Serial.print("Sonar Alarma");
    }
}

void luzconter() {
  if (contadorLuz == 30) {
    lcd.noBacklight();
    lightOn = false;
    contadorLuz = 0;
  }
}