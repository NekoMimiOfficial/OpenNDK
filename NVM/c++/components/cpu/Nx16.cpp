#pragma once
#include <iostream>
#include "../../libs/types.cpp"
#include "./NekoArchIO.cpp"

enum Instructions
{
  LDA,
  LDB,
  LDC,
  LDX,
  TXA,
  TXB,
  TXC,
  ADD,
  INT,
  JMP,
  JEQ,
  JNQ,
  HLT
};

class Machine
{
  private:
    u16 ra = 0x0;
    u16 rb = 0x0;
    u16 rc = 0x0;
    u16 rx = 0x0;
    u16 sp = 0xFFFF;
    u16 pc = 0;
    u16 xi = 0;

    bool state = 0;

  public:
    //changes the stack pointer (bios sp init)
    void point(u16 p)
    {sp = p;}

    //Load2Reg
    void lda(){}
    void ldb(){}
    void ldc(){}
    void ldx(){}

    //Transfer from Reg
    void txa(){}
    void txb(){}
    void txc(){}

    //basic ALU logic
    void add(){}

    //interupts and halts
    void sys(){}
    void hlt(){}

    //jump and conditional jump
    void jmp(){}
    void jeq(){}
    void jnq(){}

    //==============================//
    
    /*
     *Default cpu cycle includes 3 main routines
     *Fetch: increases SP
     *Decode: interprets opcode into ins and data
     *Execute: executes opcode
     * */

    void fetch(){}
    void decode(){}
    void execute(){}

};
