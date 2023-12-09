#pragma
#include <iostream>
#include "./types.cpp"

class Machine
{
  private:
    u_int16 mem[0xFF];
    u_int16 ram[0xFF];
    short pc = 0;
    u_int16 r0;
    u_int16 r1;
    u_int16 rx;

  public:

    void read()
    {}

    void write()
    {}

    void lda()
    {}

    void ldb()
    {}

};
