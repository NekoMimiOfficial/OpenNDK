#pragma once
#include <iostream>
#include "../../libs/types.cpp"

enum Instructions
{
  LDA = 0x01, //Load to A
  LDB = 0x02, //Load to B
  LDC = 0x03, //Load to C
  LDX = 0x04, //Load to X
  TXA = 0x05, //Transfer from A
  TXB = 0x06, //Transfer from B
  TXC = 0x07, //Transfer from C
  ADD = 0x08, //Addition arthimetic OP (A + B)
  INT = 0x09, //NekoPico interrupt
  JMP = 0x0A, //Jump to address
  JEQ = 0x0B, //Jump if (A == B)
  JNQ = 0x0C, //Jump if (A != B)
  NYA = 0x0D, //Machine save state
  XYZ = 0x0E, //Open domain
  HLT = 0x0F  //Halt system
};

class CPU
{
  private:
    i16 ra = 0x0;
    i16 rb = 0x0;
    i16 rc = 0x0;
    i16 rx = 0x0;
    size_t sp = 0x0;
    i16 xi = 0;

    bool state = 0;
    i16 opcode;
    i16 data;

    Ram& mem;

  public:
    //initialize cpu and connect with ram
    CPU(Ram& mem) : mem(mem){}

    //Load2Reg
    void lda(i16 addr){ra = mem.ram[addr];}
    void ldb(i16 addr){rb = mem.ram[addr];}
    void ldc(i16 addr){rc = mem.ram[addr];}
    void ldx(i16 addr){rx = mem.ram[addr];}

    //Transfer from Reg
    void txa(i16 addr){mem.ram[addr] = ra;}
    void txb(i16 addr){mem.ram[addr] = rb;}
    void txc(i16 addr){mem.ram[addr] = rc;}

    //basic ALU logic
    void add(i16 addr){mem.ram[addr] = (ra + rb);}

    //interupts and halts
    void sys(){}
    void nya(){}
    i16 hlt(i16 addr){return mem.ram[addr];}

    //jump and conditional jump
    void jmp(i16 addr){sp = addr;}
    void jeq(i16 addr){sp = (ra == rb)? addr : sp;}
    void jnq(i16 addr){sp = (ra == rb)? sp : addr;}

    //==============================//
    
    /*
     *Default cpu cycle includes 3 main routines
     *Fetch: increases SP
     *Decode: interprets opcode into ins and data
     *Execute: executes opcode
     * */

    void fetch(){sp++;}
    void decode(){}
    void execute(){}

    void arm(){state = 1;}
    void disarm(){state = 0;}

    void run()
    {
      while(state == 1)
      {
        fetch();
        decode();
        execute();
      }
    }

};
