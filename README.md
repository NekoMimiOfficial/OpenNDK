# OpenNDK

* wtf is this?  
just another Virtual Machine project that runs an architecture called nekoArch, the bytecode is refered to as "nyani" or in other words just.. "what meow?"  

* why?  
I wanted to learn how i can create a new compiled language so i needed an architecture first and i quite hate the current architectures so i decided to build my own cuz why not kekw.  



# k'ay more teknikal D-tails nyaou!

The bytecode is really simple its just 16 different instructions and for now 2 syscalls for input and output  

* Instructions  
LDA : Loads an unsigned short to register 1  
LDB : Loads an unsigned short to register 2  
LDX : Loads an unsigned short to the syscall register  
JMP : Jumps to a certain label if values in registers 1 and 2 are the same  
JNQ : Jumps to a certain label if values in registers 1 and 2 are not the same 
SUM : Sums the unsigned shorts in registers 1 and 2 to register 2  
LDS : Switches the values of registers 1 and 2  
LXS : Switches the values of registers 2 and syscall reg  
RAM : Reads memory from Ram to register 1  
WAM : Writes data from register 1 to Ram  
NYA : Makes a dump of Ram  
RET : Returns from the program with the value set in register 1  
SYS : Executes a syscall to the value in the syscall register  

* Syscalls  
CBUFO : Character Buffer Output (prints a character to the screen from reg 1)  
CBUFI : Character Buffer Input (gets a character from the user and saves it to reg 2)  

* Char map  
```
a-z : 1-26   [0x01 - 0x1A]  
A-Z : 27-51  [0x1B - 0x33]  
0-9 : 52-62  [0x34 - 0x3E]  
  
(more soon)
```

# moe tawk abwawt da instwacshons nya! 

* Okay, so you know how there is a register for syscalls in most archs? like reg7 in armv7? yeah so here i decided to do the same but id refer to it as reg 'x'  
I was puzzled due to my arch only having 2 functional registers since they weren't enought when i introduced the SUM instruction and i needed to set the output of it to a register  
so naturally i thought that some interesting code could happen if i assign the value to reg x but to play it safe i assigned it to reg 2 and i implemented an instruction called LXS that switches values between reg 2 and reg x  
it does feel wrong , very wrong to do , but it's my own arch so F it why not?  

* Then i came up with a great idea to make my "thing" unique, I  introduced the NYA syscall which can dump the ram to a file for it to get reloaded anytime again, kind of like ram savestates on old consoles but modernized (okay modernized is a huge lie)  
So the next time you are computing the mass of your aSS while your mom calls you for dinner you can just dump the memory and resume operation later!  

* Okay .. where is the HALT command?  
its 4 letters, not adding it kekw  
(actually i decided not to add it and just stick with RET)  

* How are JMP and JNQ handled and what about labels?  
see i wanted to introduce loops or functions or generally code blocks so i needed to add labels, in the assembly form you would write labels that get converted to addresses and later on the labels just get replaced with the actual address, nothing too special...  

* Variables?  
i have an easy way to implement them (crossing my fingers while i pray that poo wont randomly leek{leak} out my ass{program} as i try to keep the hopes of people who read this somewhat high{legally})  
okay basically i have ram, and i can allocate memory, and i have a varsystem (the sister of a filesystem) so basically ill create NekoFS and nekoArch and NekoLang and while im at it why not a nekoPC then dominate the world with my brands over everything!  

* And so you are creating an assembler then a programming language off your arch using your own assembler by creating your own compiler then compiling the lang using the lang itself making the VM create itself using itself???!!!11!!!!!1!1  
yes i like esolangs and VM-ceptions  
