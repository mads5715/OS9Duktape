# OS9Duktape
------------
### A new App for MacOS9 that allows you to play with JS/ECMAScript 5.1 on your old Mac

# Building
----------
For building this project you will need:
* Retro68
* An Old PPC Mac or an emulator(Sheepshaver/QEMU) with MacOS9
* A way to tranfer from your Modern machine to your old Mac
  * I recommend using FTP, and transferring the .dsk from your build folder

## Compiling
There are plenty of ways to name your build folder, and structure your source code.
I prefer to have my build folder inside my project folder, to keep my projects completely seperated on my drives.
```bash
mkdir OS9Duktape-build
cd OS9Duktape-build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/YourPathTo/toolchain/powerpc-apple-macos/cmake/retroppc.toolchain.cmake
make
```
------