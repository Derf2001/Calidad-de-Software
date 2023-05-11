uint8_t Falling_edge(int btn) {
  uint8_t newValue = digitalRead(button[btn]);
  uint8_t result = button_State[btn] != newValue && newValue == 1;
  button_State[btn] = newValue;
  if (digitalRead(button[btn]) == LOW) {  //Modificar
    //contadorLuz =0;
  }
  if (result == 1) {
    contadorLuz = 0;
  }

  return result;
}