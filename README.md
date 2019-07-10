# OS9Duktape
### A new App for MacOS9 that allows you to play with JS/ECMAScript 5.1 on your old Mac
Compiles using the [Retro68 GCC toolchain](https://github.com/autc04/Retro68).
This project is mostly for experimenting with JS and old MacOS9 and to have fun with.
# Building
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
## Built With
- [Retro68](https://github.com/antc04/Retro68) GCC toolchain for old MacOS
- [Duktape](https://github.com/svaarala/duktape)