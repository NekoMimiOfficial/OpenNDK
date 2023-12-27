#pragma once
#include "../../libs/types.cpp"

enum GFXcomm
{
  CBUF,
  CGFX
};

class GFX
{
  private:
    Ram& mem;
    size_t vramOffset = 0xFF;

  public:
    GFX(Ram& mem) : mem(mem)
    {
      size_t s = mem.ram.size();
      vramOffset = s - 0x66;
    }
};
