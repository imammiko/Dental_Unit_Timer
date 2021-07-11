
void tampilanLcd(byte fungsiLcd) {


  switch (fungsiLcd) {
    case 0  :
      homeLcd();
      break; //optional

    default : //Optional
      lcd.print("tampil kosong");
  }

  // you can have any number of case statements.


}


void homeLcd() {

  lcd.setCursor(0, 0); lcd.write(byte(0));
  char buffMax[10];//menyimpan karakter sebanyak 6 buah
  sprintf(buffMax, "%3d", timer);
  lcd.setCursor(1, 0); lcd.print("time delay:"); lcd.setCursor(12, 0); lcd.print(buffMax); lcd.print("s");


  if (!btBawah && millis() - a0.last > 200) {
    if (++timer > 100) timer = 1;
    foo.TIMER=timer;
    a0.last = millis();
    
  }
  if (!btAtas && millis() - a0.last > 200) {
    if (--timer < 1) timer = 100;
    foo.TIMER=timer;
    a0.last = millis();
  }


}
