#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <EEPROM.h>
#include <EEWrap.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


// ppin
int buttonIr[] = {4, 5};
int button[] = {6, 7, 8, 9};
int ir = A3;
//variable

// deklarasi
#define btAtas digitalRead(button[2])
#define btBawah digitalRead(button[1])
#define btTengah digitalRead(button[0])
#define btLuar digitalRead(button[3])
#define ir1 digitalRead(buttonIr[0])
#define ir2 digitalRead(buttonIr[1])
#define irT digitalRead(ir)
//variable
struct waktu {
  unsigned long last;
} a0, a1, a2, a3;
struct Foo {

  uint64_e TIMER;

};

Foo foo EEMEM;
unsigned long timer = 0;
bool statusIrT = 0;
bool sudahDiTekan = 0;
bool count = 0;

void setup() {


  Serial.begin(9600);

  // put your setup code here, to run once:


  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  pinMode(A3, INPUT_PULLUP);
  for (int x = 0; x < sizeof(buttonIr) / sizeof(int); x++) {
    pinMode(buttonIr[x], INPUT_PULLUP);

  }
  for (int x = 0; x < sizeof(button) / sizeof(int); x++) {
    pinMode(button[x], INPUT_PULLUP);

  }
  pinMode(ir, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  output(0);

  //
  timer = foo.TIMER;


}

void loop() {
  //Serial.println(digitalRead(buttonIr[0]));
  // Serial.println(ir1);
  // put your main code here, to run repeatedly:
  //Serial.println(sizeof(button)/sizeof(int));

  tampilanLcd(0);
  buttonFungsi();
  //Serial.println(irT);
  if (statusIrT && !irT) {
    statusIrT = 0;
    while (1) {
      output(1);
      Serial.println(irT);
      if (ir1 && ir2) {
        count = 1;
      }

      buttonFungsi();

      if (millis() - a2.last > (timer * 1000) || (statusIrT && count) || irT) {

        a2.last = millis();
        
        

        break;
        // Serial.println("hidup");
      }
      statusIrT = 0;
    }output(0);
    if (statusIrT && count) {
      delay(2000);
    }statusIrT = 0;
    count = 0;


  }

}

void buttonFungsi() {
  if (!ir1 && millis() - a1.last > 200) {

    a1.last = millis();
    statusIrT = 1;
    // Serial.println("hidup");
  }
  if (!ir2 && millis() - a1.last > 200) {
    a1.last = millis();
    statusIrT = 1;
    // Serial.println("hidup");
  }

}

void output(bool val) {
  digitalWrite(10, !val);
}
