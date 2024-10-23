# pico-rtos
Basic real time operating system for the Raspberry Pi Pico W and WH microcontrollers. Implements a basic round robin CPU task scheduler
for managing processes
## CMake commands
Sets the `CC` and `CXX` enviroment variables for C and C++
```CC=gcc-14 CXX=/opt/homebrew/opt/gcc/bin/g++-14 cmake -G "Unix Makefiles" /Users/nathanblackburn/programming/pico_rtos/src/task_scheduler/CMakeLists.txt```