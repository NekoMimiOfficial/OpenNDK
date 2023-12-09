#pragma once
#include <iostream>
#include "../libs/fileIO.cpp"
#include "./NekoArchIO.cpp"
#include "./NekoPico.cpp"
#include "./NekoFS.cpp"

class Machine
{
  private:
    u_int16 mem[0xFF];
    u_int16 ram[0xFF];
    u_int16 r1;
    u_int16 r2;
    u_int16 rx;

  public:

    void read(u_int16 addr)
    {r1 = mem[addr];}

    void write(u_int16 addr)
    {mem[addr] = r1;}

    void lda(u_int16 data)
    {r1 = data;}

    void ldb(u_int16 data)
    {r2 = data;}

    void ldx(u_int16 data)
    {rx = data;}

    void dump()
    {
      //very obsecure dump code here
    }

    void lds()
    {
      u_int16 swap;
      swap = r1;
      r1 = r2;
      r2 = swap;
    }

    void lxs()
    {
      u_int16 swap;
      swap = r2;
      r2 = rx;
      rx = swap;
    }

    void sum()
    {
      r2 = r1 + r2;
    }

    u_int16 peek_a()
    {return r1;}

    u_int16 peek_b()
    {return r2;}

    u_int16 peek_x()
    {return rx;}

};
