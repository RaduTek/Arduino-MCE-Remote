#define DECODE_RC6
#define HID_CUSTOM_LAYOUT
#define LAYOUT_US_ENGLISH

//#define DEBUG

#include <IRremote.hpp>
#include "HID-Project.h"

#include "rmcodes.h"

uint8_t         shrt_code=0;
KeyboardKeycode keyb_code=0;
ConsumerKeycode cons_code=0;

uint8_t key_type=KT_KEYBOARD;
unsigned long last_repeat=0;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif
  IrReceiver.begin(2);
  Consumer.begin();
  BootKeyboard.begin();
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == RC6 && IrReceiver.decodedIRData.address == 0x4) {
      if (rm_code_to_key(IrReceiver.decodedIRData.command, shrt_code, keyb_code, cons_code)) {
        if (!(IrReceiver.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT))) {

          if (shrt_code != 0) {
            key_type = KT_SHORTCUT;
          } else if (keyb_code != 0) {
            key_type = KT_KEYBOARD;
          } else if (cons_code != 0) {
            key_type = KT_CONSUMER;
          }
          
#ifdef DEBUG
          Serial.print(F("PRESS "));
          Serial.print(IrReceiver.decodedIRData.command, HEX);
          Serial.print(F(" "));
          // Serial.print(key_code, HEX);
          // Serial.print(F(" "));
#endif

          if (key_type == KT_CONSUMER) {
            Consumer.press(cons_code);
          } else if (key_type == KT_KEYBOARD) {
            Keyboard.press(keyb_code);
          } else if (key_type == KT_SHORTCUT) {
            rm_do_shortcut(shrt_code);
          }
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
    if (key_type == KT_CONSUMER) {
      Consumer.release(cons_code);
    } else if (key_type == KT_KEYBOARD) {
      Keyboard.release(keyb_code);
    }
    last_repeat = 0;
  }
}
