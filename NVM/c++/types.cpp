#pragma once

typedef unsigned short u_int16;

enum Instructions
{
  LDA = 0x0A,
  LDB = 0x0B,
  LDX = 0x0C,
  JMP = 0x01,
  JNQ = 0x02,
  LDS = 0x03,
  LXS = 0x04,
  SUM = 0x05,
  RAM = 0x06,
  WAM = 0x07,
  //REDACTED = 0x08,
  //REDACTED = 0x09,
  NYA = 0x0D,
  RET = 0x0E,
  SYS = 0x0F
};

enum Syscalls
{
  CBUFO = 0x1,
  CBUFI = 0x2
};

