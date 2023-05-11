void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < tira.numPixels(); i++) {
    tira.setPixelColor(i, color);
    tira.show();
  }
 delay(wait);  
  for (int i = 0; i < tira.numPixels(); i++) {
    tira.setPixelColor(i, 0);
    tira.show();
   // delay(wait);
  }
}


void rainbow(uint8_t wait) {
 for(uint16_t i=0; i<tira.numPixels(); i++) {
    uint32_t c = tira.ColorHSV(i * 65536L / tira.numPixels());
    for(uint16_t j=0; j<tira.numPixels(); j++) {
      tira.setPixelColor(j, c);
    }
    tira.show();
    delay(wait);
  }
}
void rainbowCycle(uint8_t wait) {
  for (int i = 0; i < tira.numPixels(); i++) {
    tira.setPixelColor(i, 255, 255, 255);
    tira.show();
    delay(wait);
    tira.setPixelColor(i, 0, 0, 0);
  }
}
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<2; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < tira.numPixels(); i=i+3) {
        tira.setPixelColor(i+q, c);    //turn every third pixel on
      }
      tira.show();

      delay(wait);

      for (int i=0; i < tira.numPixels(); i=i+3) {
        tira.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}