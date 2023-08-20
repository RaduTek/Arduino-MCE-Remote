# Arduino-MCE-Remote

USB Receiver for Windows Media Center remotes

## How it works?

This project sends keyboard shortcuts equivalent to the original functionality of the Windows Media Center remotes.

It also implements key presses properly, unlike many projects alike. When you hold down a key on the remote, the PC isn't receiving repeated key presses, instead it knows the key is held down and handles it accordingly.

In the "HP MCE Remote Codes.pdf" document I have documented all the key codes of my HP Media Center remote with their equivalent key shortcuts.

Unfortunately, there are no key shortcuts for the Teletext features (display, red, green, yellow, blue) and these keys have been reused for other functionality (opening TV, music, videos, photos).

## Requirements

- Arduino software: [download](https://www.arduino.cc/en/software)
  - IRRemote library: [GitHub](https://github.com/Arduino-IRremote/Arduino-IRremote)
  - HID-Project library: [GitHub](https://github.com/NicoHood/HID)
- an Atmega 32u4 based Arduino compatible board

## Adding and editing button commands

First, you must get the IR commands which correspond with the buttons on your remote control. For this, you can use the `ReceiveDump` example sketch.

This project is designed for remotes which use RC6 encoding, such as all Windows Media Center remotes. Using a remote with a different encoding will require some extra tweaking of the code.

Once you've got the list of your remote's IR commands, you define the keys at the beginning of the `rmcodes.h` file, like this:

```
#define RM_KEY_NAME  <Your command here>
```

Then you can add the command that the key is supposed to perform in the `switch (rm_code)` block inside the `rm_code_to_key` function, like this:

```
  switch (rm_code) {
    ...

    case RM_KEY_NAME:
      keyb_code = YOUR_KEY_LABEL;
      return true;

    ...
  }
```

For Consumer keys (media, power, browse), you have to replace `keyb_code` with `cons_code`.

For key combinations, you first define another label for your command, like:

```
#define KS_MY_SHORTCUT  <ID of the previous entry incremented>
```

Then in the `switch (rm_code)` block inside `rm_code_to_key` function you add your key and your shortcut like this:

```
case RM_KEY_NAME:
  shrt_code = KS_MY_SHORTCUT;
  return true;
```

Last step is to implement your shortcut in the `rm_do_shortcut` function, like in this example:

```
switch (key_shortcut) {
  ...

  case KS_MY_SHORTCUT:
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_T);
    Keyboard.releaseAll();
    return true;

  ...
}
```

Getting yourself familiar with either the built-in Arduino Keyboard library or the HID-Project library will help.

### Useful links

- [Reference for Consumer key code labels](https://github.com/NicoHood/HID/blob/master/src/HID-APIs/ConsumerAPI.h)
- [Reference for Keyboard key code label](https://github.com/NicoHood/HID/blob/master/src/KeyboardLayouts/ImprovedKeylayouts.h)
- [Windows Media Center keyboard shortcuts](<https://learn.microsoft.com/en-us/previous-versions/windows/desktop/windows-media-center-sdk/bb189249(v=msdn.10)>)
