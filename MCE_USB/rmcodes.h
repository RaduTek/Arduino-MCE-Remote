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
#define KS_PRINT    1
#define KS_MCE      2
#define KS_DVDMENU  3
#define KS_TV       4
#define KS_EPG      5
#define KS_TV_REC   6
#define KS_MUSIC    7
#define KS_VIDEOS   8
#define KS_PICTURES 9

// Key Command Types
#define KT_KEYBOARD 0x0
#define KT_SHORTCUT 0x1
#define KT_CONSUMER 0x2

bool rm_do_shortcut(unsigned char key_shortcut) {
  switch (key_shortcut) {
    case KS_PRINT:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_P);
      Keyboard.press(KEY_ENTER);
      Keyboard.releaseAll();
      return true;
    case KS_MCE:
      Keyboard.press(KEY_LEFT_WINDOWS);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_ENTER);
      Keyboard.releaseAll();
      return true;
    case KS_DVDMENU:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_M);
      Keyboard.releaseAll();
      return true;
    case KS_TV:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_T);
      Keyboard.releaseAll();
      return true;
    case KS_EPG:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_G);
      Keyboard.releaseAll();
      return true;
    case KS_TV_REC:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_O);
      Keyboard.releaseAll();
      return true;
    case KS_MUSIC:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_M);
      Keyboard.releaseAll();
      return true;
    case KS_VIDEOS:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_E);
      Keyboard.releaseAll();
      return true;
    case KS_PICTURES:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_I);
      Keyboard.releaseAll();
      return true;
    default:
      return false;
  }
  return false;
}


bool rm_code_to_key(uint16_t rm_code, uint8_t &shrt_code, KeyboardKeycode &keyb_code, ConsumerKeycode &cons_code) {
  shrt_code = 0;
  keyb_code = 0;
  cons_code = 0;
  switch (rm_code) {
    case RM_DVD:
      shrt_code = KS_DVDMENU;
      return true;
    case RM_POWER:
      cons_code = CONSUMER_SLEEP;
      return true;

    case RM_RED:
      shrt_code = KS_TV;
      return true;
    case RM_GREEN:
      shrt_code = KS_MUSIC;
      return true;
    case RM_YELLOW:
      shrt_code = KS_VIDEOS;
      return true;
    case RM_BLUE:
      shrt_code = KS_PICTURES;
      return true;

    case RM_RECORD:
      cons_code = MEDIA_RECORD;
      return true;
    case RM_PLAY:
      cons_code = MEDIA_PAUSE;
      return true;
    case RM_PAUSE:
      cons_code = MEDIA_PLAY_PAUSE;
      return true;
    case RM_STOP:
      cons_code = MEDIA_STOP;
      return true;
    case RM_NEXT:
      cons_code = MEDIA_NEXT;
      return true;
    case RM_PREV:
      cons_code = MEDIA_PREVIOUS;
      return true;
    case RM_F_FWD:
      cons_code = MEDIA_FAST_FORWARD;
      return true;
    case RM_F_RWD:
      cons_code = MEDIA_REWIND;
      return true;
      
    case RM_BACK:
      keyb_code = KEY_BACKSPACE;
      return true;
    case RM_INFO:
      keyb_code = KEY_MENU;
      return true;
      
    case RM_UP:
      keyb_code = KEY_UP_ARROW;
      return true;
    case RM_DOWN:
      keyb_code = KEY_DOWN_ARROW;
      return true;
    case RM_LEFT:
      keyb_code = KEY_LEFT_ARROW;
      return true;
    case RM_RIGHT:
      keyb_code = KEY_RIGHT_ARROW;
      return true;
    case RM_OK:
      keyb_code = KEY_ENTER;
      return true;
      
    case RM_VOL_UP:
      cons_code = MEDIA_VOL_UP;
      return true;
    case RM_VOL_DN:
      cons_code = MEDIA_VOL_DOWN;
      return true;
    case RM_CH_UP:
      keyb_code = KEY_PAGE_UP;
      return true;
    case RM_CH_DN:
      keyb_code = KEY_PAGE_DOWN;
      return true;
      
    case RM_MCE:
      shrt_code = KS_MCE;
      return true;
    case RM_MUTE:
      cons_code = MEDIA_VOL_MUTE;
      return true;

    case RM_TV:
      shrt_code = KS_TV;
      return true;
    case RM_EPG:
      shrt_code = KS_EPG;
      return true;
    case RM_TV_REC:
      shrt_code = KS_TV_REC;
      return true;
    
    case RM_1:
      keyb_code = KEY_1;
      return true;
    case RM_2:
      keyb_code = KEY_2;
      return true;
    case RM_3:
      keyb_code = KEY_3;
      return true;
    case RM_4:
      keyb_code = KEY_4;
      return true;
    case RM_5:
      keyb_code = KEY_5;
      return true;
    case RM_6:
      keyb_code = KEY_6;
      return true;
    case RM_7:
      keyb_code = KEY_7;
      return true;
    case RM_8:
      keyb_code = KEY_8;
      return true;
    case RM_9:
      keyb_code = KEY_9;
      return true;
    case RM_0:
      keyb_code = KEY_0;
      return true;
      
    case RM_CLEAR:
      keyb_code = KEY_BACKSPACE;
      return true;
    case RM_PRINT:
      shrt_code = KS_PRINT;
      return true;
    case RM_ENTER:
      keyb_code = KEY_ENTER;
      return true;
    default:
      return false;
  }
  return false;
}
