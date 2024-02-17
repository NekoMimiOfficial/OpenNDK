#include <iostream>
#include "../meta.c++"
#include "./components/Ram16k.cpp"
#include "./components/Nx16.h"

int main (int argc, char *argv[]) {
  printf("%s\n",global_VERSION);
  RAM ram;
  // ram.ram[0x39] = 0xFFFFFFFF;
  ram.ram[0x39] = 0x1111ABCD;
  CPU cpu(ram);
  cpu.step();
  return 0;
}
