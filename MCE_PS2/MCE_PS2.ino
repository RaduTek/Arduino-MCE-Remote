#define DECODE_RC6

//#define DEBUG

#include <IRremote.hpp>
#include <ps2dev.h> 

PS2dev keyboard(3, 4);

#include "rmcodes.h"

unsigned char key_code=0;
bool key_special, key_shortcut;
unsigned long last_repeat=0;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif
  keyboard.keyboard_init();
  IrReceiver.begin(2);
}

void loop() {
  
  unsigned char leds;
  if (keyboard.keyboard_handle(&leds)) {
#ifdef DEBUG
    Serial.print(F("LEDS "));
    Serial.println(leds, BIN);
#endif
  }
  
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == RC6 && IrReceiver.decodedIRData.address == 0x4) {
      if (rm_code_to_key(IrReceiver.decodedIRData.command, key_code, key_special, key_shortcut)) {
        if (!(IrReceiver.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT))) {
          if (!key_shortcut) {
#ifdef DEBUG
            Serial.print(F("PRESS "));
            Serial.print(IrReceiver.decodedIRData.command, HEX);
            Serial.print(F(" "));
            Serial.print(key_code, HEX);
            Serial.print(F(" "));
#endif
            if (key_special) {
              keyboard.keyboard_special_press(key_code);
            } else {
              keyboard.keyboard_press(key_code);
            }
          }
#ifdef DEBUG
          else {
            Serial.print(F("SHORTCUT ID "));
            Serial.println(key_code);
          }
#endif
        }
        last_repeat = millis();
      }
    }
    IrReceiver.resume();
  } else if (last_repeat > 0 && millis() - last_repeat >= 110) {
#ifdef DEBUG
    Serial.print(F("RELEASE "));
    Serial.println(millis() - last_repeat);
#endif
    if (key_special) {
      keyboard.keyboard_special_release(key_code);
    } else {
      keyboard.keyboard_release(key_code);
    }
    last_repeat = 0;
  }
}
