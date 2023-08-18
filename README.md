# Arduino-MCE-Remote
USB Receiver for Windows Media Center remotes

## How it works?
This project sends keyboard shortcuts equivalent to the original functionality of the Windows Media Center remotes. 

It also implements key presses properly, unlike many projects alike. When you hold down a key on the remote, the PC isn't receiving repeated key presses, instead it knows the key is held down and handles it accordingly.

In [this](./HP MCE Remote Codes.pdf) document I have all the key codes of my HP Media Center remote with their equivalent key shortcuts.

Unfortunately, there are no key shortcuts for the Teletext features (display, red, green, yellow, blue) and these keys have been reused for other functionality (opening TV, music, videos, photos).
