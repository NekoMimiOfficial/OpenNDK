#include <iostream>
#include "./libs/err.c++"
#include "./components/ram/NekoDIMM.cpp"
#include "./components/ICTL/NID.cpp"
#include "./components/video/nGFXctl.cpp"
#include "./components/bios/NekoFS.cpp"
#include "./components/bios/NekoPico.cpp"
#include "./components/cpu/Nx16.cpp"

int main()
{
  Ram ram(0xFFF); //Allocate 65535b of RAM
  GFX gfx(ram);
  CPU cpu(ram);
  return 0;
}
