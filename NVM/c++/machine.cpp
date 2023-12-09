#include "./nekoArch.cpp"
#include "./IOtils.cpp"

using std::cout;
using std::cin;

int main()
{
  cout << " ^ ^   |OpenJDK Nyani bytecode VM     v[1.0]|\n";
  cout << "=UwU=  |This programs comes with no warranty|\n";
  cout << " w w   |NekoMimi @ NekoLabs LLC      2023(c)|\n";

  cout << "\nW: code execution is unsafe\n";
  cout << "=============================================\n";

  int hold;
  int regKey;
  Machine machine;

  machine.push(Machine::ID::HALT);
  machine.push(99);
  machine.push(0);
  machine.push(Machine::ID::LDX);
  machine.push(10);
  machine.push(Machine::ID::JMP);
  machine.push(4);
  machine.push(Machine::ID::JEQU);
  machine.push(Machine::ID::PRINT);
  machine.push(Machine::ID::INPUT);
  machine.push(56);
  machine.push(1);
  machine.push(Machine::ID::LDX);

  for (;;)
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
        regKey = machine.pop();
        if (regKey == 0) {machine.set0(machine.pop());}
        else if (regKey == 1) {machine.set1(machine.pop());}
        else {cout << "LDX error \n"; return 39;}
        break;

      case Machine::ID::INPUT:
        cout << "> ";
        cin >> hold;
        machine.set0(hold);
        break;

      case Machine::ID::JMP:
        machine.jump(machine.pop());
        break;

      case Machine::ID::JEQU:
        machine.jq(machine.pop());
        break;
    }
  }

  return 0;
}
