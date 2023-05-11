void SensorIR() {
  
  if (irrecv.decode(&results)) {
    lastButtonPress = millis();
    Serial.print("irCode: ");
    Serial.print(results.value, HEX);
    Serial.print(", bits: ");
    Serial.println(results.bits);
    tira.show();
        

    //ROJO
    if (0x010 == results.value) {
      
      state = C_ROJO;
    }
    if (0x810 == results.value) {
      state = C_AZUL;
    }
    if (0x410 == results.value) {
      state = C_VERDE;
    }

    //APAGAR
    if (0xFFA25D == results.value) {
      tira.clear();
      tira.show();
      state = 9;
    }
    
    irrecv.resume();
  }
}

void SensorPIR() {
  if (digitalRead(PIRPin) == HIGH) {
    state = color_aterior;
    // anterior = S_OFF;
    lastButtonPress = millis();
    //Serial.println("josue el chamber");
  } else if (millis() - lastButtonPress > 10000) {
    state = OFF;
  }
}
void BTN_Control() {
  unsigned long currentTime = millis();
  if (digitalRead(BTN_MODO) == HIGH) {
    Serial.println("Boton detectado");
    if (state == OFF) {
      state = color_aterior;
    } else {
      state++;
      state = state % 4;
    }

    if (!buttonState) {
      lastButtonPressTime = currentTime;
      buttonState = true;
    } else {
      state--;
      state = state % 4;
    }
    if (currentTime - lastButtonPressTime >= 1000) {
      FSM_Modo();
      buttonState = false;
    }
    lastButtonPress = millis();
  } else {
    buttonState = false;
  }
  if (millis() - lastButtonPress > 10000) {
    state = OFF;
  }
}