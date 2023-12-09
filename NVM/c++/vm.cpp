#include <iostream>
#include "./components/NekoArch.cpp"

using std::cout;
using std::cin;

int main()
{
  Machine NPC;
  NPC.lda(0x05);
  NPC.lds();
  std::cout << NPC.peek_b() << std::endl;
  return 0;
}
