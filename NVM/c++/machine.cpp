#include <iostream>
#include "./nekoArch.cpp"

using std::cout;
using std::cin;

int main()
{
  Machine machine;

  machine.push(Machine::ID::HALT);
  machine.push(99);
  machine.push(0);
  machine.push(Machine::ID::LDX);
  machine.push(Machine::ID::PRINT);
  machine.push(42);
  machine.push(0);
  machine.push(Machine::ID::LDX);

  for (int i = 0; i <= 7; i++)
  {
    switch (machine.pop())
    {
      case Machine::ID::HALT:
        cout << "Program Terminated\n";
        return machine.halt();
        break;

      case Machine::ID::PRINT:
        machine.print();
        break;

      case Machine::ID::LDX:
        i += 2;
        int regKey = machine.pop();
        if (regKey == 0) {machine.set0(machine.pop());}
        else if (regKey == 1) {machine.set1(machine.pop());}
        else {cout << "LDX error \n"; return 39;}
        break;
    }
  }

  return 0;
}
