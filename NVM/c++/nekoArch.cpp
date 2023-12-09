#pragma
#include <iostream>

class Machine
{
  private:
    int stack[1024*8];
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

    int pop()
    {
      int val = stack[pc--];
      return val;
    }

    void push(int x)
    {
      stack[++pc] = x;
      return;
    }

    void replace(int x)
    {
      stack[pc] = x;
      return;
    }

    void jump(int x)
    {
      pc = x;
      return;
    }

    void jq(int x)
    {
      if (r0 == r1)
      {
        pc = x;
        return;
      }
      return;
    }

    void set0(int x)
    {
      r0 = x;
    }

    void set1(int x)
    {
      r1 = x;
    }

    int halt()
    {
      return r0;
    }

    void print()
    {
      std::cout << r0 << "\n";
      return;
    }
};
