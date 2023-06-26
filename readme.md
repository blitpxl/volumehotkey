# About
![volume](https://github.com/blitpxl/volumehotkey/blob/master/img/volume.png?raw=true)
The volume-adjust slider usually can be triggered only with laptop keyboards that has the built-in volume key. Well now you could do it with regular keyboards too! Just press `ALT`+`F8` to increase the volume, and `ALT`+`F7` to reduce the volume.

# Modifying the shortcut keys
By default the app is configured with `ALT`+`F8` to increase the volume, and `ALT`+`F7` to reduce the volume. You can change the shortcut keys by modifying `the keys.txt` file, which will look like this:
```
0x1
0x77
0x76
```
the first line is the value for modifier keys such as `CTRL`, `ALT` and`SHIFT`.
You can lookup the key name and value below:
| Value | Key Name |
|-------|----------|
| 0x1   | ALT      |
| 0x2   | CTRL     |
| 0x4   | SHIFT    |
| 0x8   | WIN      |
The second line is the value for increase-volume key, and the third line is the value for decrease-volume key. By default it is set to `F8` to increase and `F7` to decrease.
You can lookup the key name and value [here](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes).

# Resource usage
Barely.
![](https://github.com/blitpxl/volumehotkey/blob/master/img/usage.png?raw=true)
