#include <iostream>
#include "./components/ram/NekoDIMM.cpp"
#include "./components/ICTL/NID.cpp"
#include "./components/video/nGFXctl.cpp"
#include "./components/bios/NekoFS.cpp"
#include "./components/bios/NekoPico.cpp"
#include "./components/cpu/Nx16.cpp"

using std::cout;
using std::cin;

int main()
{
  Ram ram(0xFFFF); //Allocate 65535b of RAM
  return 0;
}
