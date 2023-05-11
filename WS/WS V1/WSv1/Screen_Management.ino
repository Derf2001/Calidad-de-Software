 void FSM_Screen() {
  switch (ScreenState) {
    case S_WELCOME:
      cleanScreen();
      ScreenState = S_DATEHOUR;
      break;
    case S_DATEHOUR:
      cleanScreen();
      ScreenState = S_HUMTEMP;
      break;
    case S_HUMTEMP:
      cleanScreen();
      ScreenState = S_DATEHOUR;
      break;
    default:
      break;
  }
}

void RefreshScreen() {
  switch (ScreenState) {
    case S_WELCOME:
      displayWelcome();
      break;
    case S_DATEHOUR:
      displayDate();
      displayHour();
      break;
    case S_HUMTEMP:
      displayHum();
      displayTemperaturaRTC();
      break;
    default:
      break;
  }
}

void displayWelcome() {
  lcd.setCursor(0, 1);
  lcd.print("Welcome c:");
}

void displayDate() {
  formatoFecha(_bufferFecha, now.day(), now.month(), now.year());
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(_bufferFecha);
}

void displayHour() {
  formatoHora(_bufferHora, now.hour(), now.minute(), now.second());
  lcd.setCursor(0, 1);
  lcd.print("Hour: ");
  lcd.print(_bufferHora);
}

void displayHum() {
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(hum);
  lcd.print("%");
}

void displayTemp() {
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(symbol);
  lcd.print("C");
}

void displayTemperaturaRTC() {
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(symbol);
  lcd.print("C");
}