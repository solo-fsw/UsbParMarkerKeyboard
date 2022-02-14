
/*
  Usb Parallel Marker Keyboard Versie 1 Build 1 6-4-2021
  Copyright Leiden University - SOLO
*/

/* IMPORTANT NOTE
  TXLED must be disabled to prevent Interference with PORTD, done with #UNDEF
*/

#include <Keyboard.h>
#include <ButtonDebounce.h>

#undef TX_RX_LED_INIT  //DDRD |= (1<<5), DDRB |= (1<<0)
#undef TXLED0    //  PORTD |= (1<<5)
#undef TXLED1    //  PORTD &= ~(1<<5)
#undef RXLED0    //  PORTB |= (1<<0)
#undef RXLED1    //  PORTB &= ~(1<<0)

#define BUTTON1 A1  //=PF6 pins_arduino.h for description

ButtonDebounce button(BUTTON1, 5);

void setup() {
  pinMode(BUTTON1, INPUT_PULLUP);
  button.setCallback(buttonChanged);  //callback switch for marker sending
  Serial.begin(115200);
  Keyboard.begin();
}

void loop() {
  button.update();
}

void buttonChanged(int state) {   //Trigger Button handeling
  if (state == 0) {              //Button pressed
   Keyboard.print("5");
  }
}

