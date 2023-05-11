void sensorDate() {
  now = rtc.now();
}

void sensorHour() {
  now2 = rtc.now();
}

void formatoFecha(char bufferFecha[12], int numDia, int numMes, int numA) {
  sprintf(bufferFecha, "%02d/%02d/%04d", numDia, numMes, numA);
}
void formatoHora(char bufferHora[10], int hora, int minu, int seg) {
  sprintf(bufferHora, "%02d:%02d:%02d", hora, minu, seg);
}

void sensorTemperaturaRTC() {
  temp = rtc.getTemperature();
}

void sensorHum() {
  hum = dht11.readHumidity();
}

void sensorTemp() {
  tempC = dht11.readTemperature();
}
