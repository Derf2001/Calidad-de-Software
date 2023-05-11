
void incrementarHoras() {
  horas++;
  horas = horas % 24;
  actualizar = true;
}

void decrementarHoras() {
  horas--;
  if (horas < 0) {
    horas = 23;
  }
  actualizar = true;
}

void incrementarMinutos() {
  minutos++;
  minutos = minutos % 60;
  actualizar = true;
}

void decrementarMinutos() {
  minutos--;
  if (minutos < 0) {
    minutos = 59;
  }
  actualizar = true;
}

void incrementarHorasAlarm() {
  horas_alarma++;
  horas_alarma = horas_alarma % 24;
  actualizar = true;
}

void decrementarHorasAlarm() {
  horas_alarma--;
  if (horas_alarma < 0) {
    horas_alarma = 23;
  }
  actualizar = true;
}

void incrementarMinutosAlarm() {
  minutos_alarma++;
  minutos_alarma = minutos_alarma % 60;
  actualizar = true;
}

void decrementarMinutosAlarm() {
  minutos_alarma--;
  if (minutos_alarma < 0) {
    minutos_alarma = 59;
  }
  actualizar = true;
}
