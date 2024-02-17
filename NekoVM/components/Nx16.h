enum Instructions {
  LDR1, 
  LDR2, 
  LDR3, 
  LDR4, 
  LDRX, 
  STR1, 
  STR2, 
  STR3, 
  STR4, 
  STRX, 
  CMP1, 
  CMP2, 
  CMP3, 
  CMP4, 
  JMP, 
  JMC, 
  ADD12, 
  ADD34, 
  ADD13, 
  ADD24, 
  FLAG_N, 
  FLAG_C, 
  IS_N, 
  IS_C, 
  MLT12, 
  MLT34, 
  MLT13, 
  MLT24, 
  DIV12, 
  DIV34, 
  DIV13, 
  DIV24, 
  TX12, 
  TX21, 
  TX34, 
  TX43, 
  TX13, 
  TX31, 
  TX24, 
  TX42, 
  TX3X, 
  RUNX, 
  HALT, 
  PUSH, 
  POP
};

class CPU
{
  private:
    uint16_t r1;
    uint16_t r2;
    uint16_t r3;
    uint16_t r4;
    uint16_t rx;

    uint16_t pc = 0x38;
    uint16_t sp = 0xDDFF;

    uint16_t a;
    uint16_t n;

    uint32_t read;
    uint16_t opCode;
    uint16_t data;
    
    RAM& mem;

    void ld1();
    void ld2();
    void ld3();
    void ld4();
    void ldx();
    void st1();
    void st2();
    void st3();
    void st4();
    void cmp1();
    void cmp2();
    void cmp3();
    void cmp4();
    void jmp();
    void jmc();
    void add12();
    void add34();
    void add13();
    void add24();
    void mlt12();
    void mlt34();
    void mlt13();
    void mlt24();
    void div12();
    void div34();
    void div13();
    void div24();
    void tx12();
    void tx21();
    void tx34();
    void tx43();
    void tx13();
    void tx31();
    void tx24();
    void tx42();
    void runx();
    void halt();
    void is_n();
    void is_c();
    void flag_n();
    void flag_c();
    void push();
    void pop();

  public:
    CPU(RAM& ram) : mem(ram){}

    void fetch()
    {
      pc++;
    }
    void decode()
    {
      read = 0x0;
      opCode = 0x0;
      data = 0x0;

      read = mem.ram[pc];
      opCode = (read >> 16) & 0xFFFF;
      data = read & 0xFFFF;
    }
    void execute()
    {
      std::cout << "0x" << std::hex << read;
      printf("\n");
      std::cout << "0x" << std::hex << opCode;
      printf("\n");
      std::cout << "0x" << std::hex << data;
      printf("\n");
    }

    void step();
};
