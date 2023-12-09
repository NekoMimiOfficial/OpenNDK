#pragma
#include <iostream>

class Machine
{
  private:
    int mem[1024*8];
    int pc = 0;
    int r0;
    int r1;
  public:

    enum ID
    {
      HALT = 42, 
      LDX = 39, 
      SUM = 69, 
      JEQU = 70, 
      PRINT = 11, 
      JMP = 32, 
      INPUT = 50, 
      REP = 12
    };

    void read()
    {}

    void write()
    {}

    void reg_1()
    {}

    void reg_2()
    {}

};
