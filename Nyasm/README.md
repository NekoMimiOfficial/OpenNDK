# Nyani bytecode assembler (nyasm) 
First we need to establish how the Nx16 CPU works,  
each cycle itt pulls an instruction from RAM then  
divides it to 2 parts, the opCode and the data  

opCode is executed and given the data which is an address  
so basically we need to turn our instructions into opCode  
alongside its data, take `0x01D4` for example,  
the single hex code represents `0x01` which is LDA  
and `0xD4` which is a value, basically this says:  
Load the data in address 0xD4 of RAM to Reg A  

The assembler will create a program to be loaded in RAM  
offset by 100 values which is the start point of execution  
it will also calculate addresses for labels in order  
for jump instructions to work  

Nyani assembly is written differently than regular asm  
each label is contained within a file, you pass the project folder to nyasm which will search for start.nas, basically close to java classes in principal  
you can refactor code very easily this way, and it also allows the creation of NyaHub, the Nyani Label Manager (instead of a package or module manager like pip)  
isolating labels is the intended way of writing Nyani  


a list of CPU instructions for the Nx16 architecture can  
be found at the Docs main folder...
