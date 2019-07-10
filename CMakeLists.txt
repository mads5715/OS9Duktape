# HOW TO BUILD USING CMAKE as a standalone project:
# mkdir build
# cd build
# cmake .. -DCMAKE_TOOLCHAIN_FILE=/YourPath/toolchain/powerpc-apple-macos/cmake/retroppc.toolchain.cmake
# make
cmake_minimum_required(VERSION 3.12)

add_application(OS9Duktape
    main.cc
    Utilities/duktape/duktape.c
    CONSOLE
   )

set_target_properties(OS9Duktape PROPERTIES COMPILE_OPTIONS -ffunction-sections)
if(CMAKE_SYSTEM_NAME MATCHES Retro68)
	set_target_properties(OS9Duktape PROPERTIES LINK_FLAGS "-Wl,-gc-sections -Wl,--mac-strip-macsbug")
else()
	set_target_properties(OS9Duktape PROPERTIES LINK_FLAGS "-Wl,-gc-sections")
endif()
