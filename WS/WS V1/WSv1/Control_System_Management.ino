
void FSM_System() {
  switch (SystemState) {
    case S_HOME:
      break;
    case S_REFRESH:
      RefreshScreen();
      break;
    case S_READSENSORS:
      sensorDate();
      sensorHour();
      sensorTemperaturaRTC();
      sensorHum();
      //sensorTemp();
      break;
    case S_FSM_SCREEN:
      FSM_Screen();
      break;
    default:
      break;
  }

  if (SystemState != S_HOME)
    SystemState = S_HOME;
}

void cleanScreen() {
  lcd.clear();
}

void FSM_Transitions() {
  unsigned long currentMillis = millis();

  if (((currentMillis - previousMillisSA) >= timeInterval_A) && (SystemState == S_HOME)) {
    previousMillisSA = currentMillis;
    SystemState = S_REFRESH;
  }

  if (((currentMillis - previuosMillisSB) >= timeInterval_B) && (SystemState == S_HOME)) {
    previuosMillisSB = currentMillis;
    SystemState = S_READSENSORS;
  }

  if (((currentMillis - previuosMillisSC) >= timeInterval_C) && (SystemState == S_HOME)) {
    previuosMillisSC = currentMillis;
    SystemState = S_FSM_SCREEN;
  }
}
