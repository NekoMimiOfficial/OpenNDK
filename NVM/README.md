# Nyani Virtual Machine  
This is a state of the art VM that is so borked that i had to add more functionalities to me assembler to make the cpu useful at all  

the cpu can only read, write, add, jump, interrupt  
yes lassies and lassos, it's a POS (piece of software)  
i mean technically you only need to be able to add in a cpu  
like substraction can be addition, so can be multiplication, and ill somehow make division  

what data can it work with?  
16 BIT  

and that by itself is a lie  
this VM uses 16bit data which is yet again split to 0xFF for the opCode and 0xFFFF for th actual data, and the negative byte is the first F, so you can either work with signed data that utilize the negative form or stay unsigned and use the full 0xFFFF  

kay.. the cpu is trash.. what else?  
Ram is configurable, and is at least 0xFFFF (0xFF00 usable)  
GFX is console IO and later a screen of 360x240  
IO are handled via a controler (NekoPico interrupt)  
INET is a joke  
SOUND is a joke  

so till this point of time its still crappy AF, but its supposed to be a very minimalistic VM (its being maintained by me and only me so give me an xcuz plz plus i have more projektz 2)  
okay so now and randomly i want to talk about yet another weird choice...  
so you know that each nyani binary is offset by 99 positions in memory? thats so you can store some metadata about what that bin file type is and more stuffz, but more importantly there is a special location 0x86 which is used as a temp memory address for any operation, its what the convention of a functioning nyani binary is  
so the ICTL saves values from the user to that address, if you want to save the sum value temporarily until you load it to a register its best saved there, a temp/changing jump address .. there!  
random data? you get it from there (well.. now you know why i chose to do this.. its not perfect but its a salt..)  

more info about the structure of a nyani binary at the Docs...  
