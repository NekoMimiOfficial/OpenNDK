#pragma once
#include <iostream>
#include "../../libs/types.cpp"
#include "./NekoArchIO.cpp"

enum Instructions
{
  LDA = 0x01,
  LDB = 0x02,
  LDC = 0x03,
  LDX = 0x04,
  TXA = 0x05,
  TXB = 0x06,
  TXC = 0x07,
  ADD = 0x08,
  INT = 0x09,
  JMP = 0x0A,
  JEQ = 0x0B,
  JNQ = 0x0C,
  HLT = 0x0D
};

class CPU
{
  private:
    u16 ra = 0x0;
    u16 rb = 0x0;
    u16 rc = 0x0;
    u16 rx = 0x0;
    u16 sp = 0xFFFF;
    u16 xi = 0;

    bool state = 0;
    u16 opcode;
    u16 data;

  public:
    //changes the stack pointer (bios sp init)
    void point(u16 p)
    {sp = p;}

    //initialize cpu and connect with ram
    void CPU(u16 mem){u16 mem = mem;}

    //Load2Reg
    void lda(u16 addr){ra = mem[addr];}
    void ldb(u16 addr){rb = mem[addr];}
    void ldc(u16 addr){rc = mem[addr];}
    void ldx(u16 addr){rx = mem[addr];}

    //Transfer from Reg
    void txa(u16 addr){mem[addr] = ra;}
    void txb(u16 addr){mem[addr] = rb;}
    void txc(u16 addr){mem[addr] = rc;}

    //basic ALU logic
    void add(u16 addr){mem[addr] = (ra + rb);}

    //interupts and halts
    void sys(){}
    void hlt(u16 addr){return mem[addr];}

    //jump and conditional jump
    void jmp(u16 addr){sp = addr;}
    void jeq(u16 addr){sp = (ra == rb)? addr : sp;}
    void jnq(u16 addr){sp = (ra == rb)? sp : addr;}

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

};
