// Remote Control Buttons

#define RM_DVD    0x24
#define RM_POWER  0xC
#define RM_TEXT   0x5A

#define RM_RED    0x5B
#define RM_GREEN  0x5C
#define RM_YELLOW 0x5D
#define RM_BLUE   0x5E

#define RM_F_FWD  0x14
#define RM_F_RWD  0x15
#define RM_PLAY   0x16
#define RM_RECORD 0x17
#define RM_PAUSE  0x18
#define RM_STOP   0x19
#define RM_NEXT   0x1A
#define RM_PREV   0x1B

#define RM_BACK   0x23
#define RM_INFO   0xF

#define RM_UP     0x1E
#define RM_DOWN   0x1F
#define RM_LEFT   0x20
#define RM_RIGHT  0x21
#define RM_OK     0x22

#define RM_VOL_UP 0x10
#define RM_VOL_DN 0x11
#define RM_CH_UP  0x12
#define RM_CH_DN  0x13

#define RM_MCE    0xD
#define RM_MUTE   0xE

#define RM_TV     0x25
#define RM_EPG    0x26
#define RM_TV_REC 0x48

#define RM_0  0x0
#define RM_1  0x1
#define RM_2  0x2
#define RM_3  0x3
#define RM_4  0x4
#define RM_5  0x5
#define RM_6  0x6
#define RM_7  0x7
#define RM_8  0x8
#define RM_9  0x9

#define RM_POUND  0x1C
#define RM_STAR   0x1D
#define RM_CLEAR  0xA
#define RM_PRINT  0x4E
#define RM_ENTER  0xB

// Key Shortcut IDs
#define KS_PRINT  0x1
#define KS_MCE    0x2

bool rm_do_shortcut(unsigned char key_shortcut) {
  switch (key_shortcut) {
    case KS_PRINT:
      keyboard.keyboard_press(PS2dev::LEFT_CONTROL);
      keyboard.keyboard_mkbrk(PS2dev::P);
      keyboard.keyboard_release(PS2dev::LEFT_CONTROL);
      return true;
    case KS_MCE:
      keyboard.keyboard_special_press(PS2dev::LEFT_WIN);
      keyboard.keyboard_press(PS2dev::LEFT_ALT);
      keyboard.keyboard_mkbrk(PS2dev::ENTER);
      keyboard.keyboard_release(PS2dev::LEFT_ALT);
      keyboard.keyboard_special_release(PS2dev::LEFT_WIN);
      return true;
    default:
      return false;
  }
  return false;
}


bool rm_code_to_key(uint16_t rm_code, unsigned char &key_code, bool &key_special, bool &key_shortcut) {
  key_code = 0;
  key_special = false;
  key_shortcut = false;
  switch (rm_code) {
    case RM_POWER:
      key_code = PS2dev::POWER;
      key_special = true;
      return true;

    case RM_PLAY:
    case RM_PAUSE:
      key_code = PS2dev::PLAY_PAUSE;
      key_special = true;
      return true;
    case RM_STOP:
      key_code = PS2dev::STOP;
      key_special = true;
      return true;
    case RM_NEXT:
      key_code = PS2dev::NEXT_TRACK;
      key_special = true;
      return true;
    case RM_PREV:
      key_code = PS2dev::PREVIOUS_TRACK;
      key_special = true;
      return true;
      
    case RM_BACK:
      key_code = PS2dev::BACKSPACE;
      return true;
    case RM_INFO:
      key_code = PS2dev::MENUS;
      key_special = true;
      return true;
      
    case RM_UP:
      key_code = PS2dev::UP_ARROW;
      key_special = true;
      return true;
    case RM_DOWN:
      key_code = PS2dev::DOWN_ARROW;
      key_special = true;
      return true;
    case RM_LEFT:
      key_code = PS2dev::LEFT_ARROW;
      key_special = true;
      return true;
    case RM_RIGHT:
      key_code = PS2dev::RIGHT_ARROW;
      key_special = true;
      return true;
    case RM_OK:
      key_code = PS2dev::ENTER;
      return true;
      
    case RM_VOL_UP:
      key_code = PS2dev::VOLUME_UP;
      key_special = true;
      return true;
    case RM_VOL_DN:
      key_code = PS2dev::VOLUME_DOWN;
      key_special = true;
      return true;
    case RM_CH_UP:
      key_code = PS2dev::PAGE_UP;
      key_special = true;
      return true;
    case RM_CH_DN:
      key_code = PS2dev::PAGE_DOWN;
      key_special = true;
      return true;
      
    case RM_MCE:
      key_code = PS2dev::LEFT_WIN;
      key_special = true;
      return true;
    case RM_MUTE:
      key_code = PS2dev::MUTE;
      key_special = true;
      return true;
    
    case RM_1:
      key_code = PS2dev::ONE;
      return true;
    case RM_2:
      key_code = PS2dev::TWO;
      return true;
    case RM_3:
      key_code = PS2dev::THREE;
      return true;
    case RM_4:
      key_code = PS2dev::FOUR;
      return true;
    case RM_5:
      key_code = PS2dev::FIVE;
      return true;
    case RM_6:
      key_code = PS2dev::SIX;
      return true;
    case RM_7:
      key_code = PS2dev::SEVEN;
      return true;
    case RM_8:
      key_code = PS2dev::EIGHT;
      return true;
    case RM_9:
      key_code = PS2dev::NINE;
      return true;
    case RM_0:
      key_code = PS2dev::ZERO;
      return true;
      
    case RM_CLEAR:
      key_code = PS2dev::ONE;
      return true;
    case RM_PRINT:
      key_code = KS_PRINT;
      key_shortcut = true;
      rm_do_shortcut(KS_PRINT);
      return true;
    default:
      return false;
  }
  return false;
}
