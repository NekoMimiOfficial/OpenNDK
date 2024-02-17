# OpenNDK Journal/Diary

```
note that this journal contains very false info about the project  
since its been changed over and over, and it only serves as a  
timeline for how/what my thoughts were at that point and what i  
plan to do now  
```

* wtf is this?  
just another Virtual Machine project that runs an architecture called nekoArch, the bytecode is refered to as "nyani" or in other words just.. "what meow?"  

* why?  
I wanted to learn how i can create a new compiled language so i needed an architecture first and i quite hate the current architectures so i decided to build my own cuz why not kekw.  

* Boi dis is too much for a projekt  
yesh it iz, but its a good way of learning how computers actually work, unlike uncle joe who thinks there is a monkeh inside yer compooter that does all the werk  
However thine shalt warn thou whom plan to use thy magic machine, OpenJDK hast a workflow not so standard per peasently machines as thy hast assended to higher levels of engineering...  
alright let's cut this crap talk, it works, it resembles a real system, thats all, its not a 1 to 1 replica but its close enough, it works really well tho (foreshadowing the opposite)  


# k'ay more teknikal D-tails nyaou!

The bytecode is really simple its just 16 different instructions and for now 2 syscalls for input and output  

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

* So i ended up with a couple of rewrites..  
yes I'm still learning how a cpu actually functions alongside other components, plus this isnt supposed to be a real PC emulator so im not adding syscalls since i dont have an "OS", i do have a BIOS but thats it, character writing will now be handled by the GFX controller via embedded vram addresses, basically give it a render instruction along the data to render, like a render char inst and itll associate the value with a character on the char list and print it, later on im planning to add a 360x240 display renderer for "complex" GFX,  with a frame buffer that can be directly written to, basicllay it renders a Panel with black pixels that can be manipulated manually, additionally a sprite map can be used that would be stored in a different memory medium (sprite ROM), these are all plans tho, character rendering is what ill support for now, ICTL is gonna handle input from the keyboard  

* wait why is dis redme wrong???  
you can see a lotz of stuff is wrong since i decided to do some rewrites as i learned more about cpus, i wont remove old stuff as the real docs are in the Docs folder and since this kinda works as a reminder to what my old versions used to work like, its fun and its similar to a diary/blog(eww), also i like the old jokes so they gunna stay  
yes there is no such thing as syscalls anymore, RET is now HLT, and everything i said i was gonna do made a 180 and is now a thing of the past in favour of a more correct vision and hopefully "PROduct"  

* dont you go insane dealing with all the complexities and errors?  
CUZ MOOZIK IZ MA BEST FREND!  

* Why choose/sponsor OpenNDK  
okay imagine this scenario:  
your boss comes up to your desk but you are playing an addictive game and you wanna close it asap but you'll lose your save, EZ! we got ram dumps on exit(when implemented in an app)... okay okay i should stop milking the cow dry I've already talked about this a LOTZ!  
KK! picture this:  
you wanna build an application that you just want it to work on any platform, with NVM you can run Nyani bytecode without recompiling (so.. its like java?) Nuuuu! java bad!, Nyani is fast! (which actually is somewhat true, its faster than java at least "if i can write an efficient NekoLang compiler")  
so you tell me its a fast VM with savestates?  
yes pretty much  
also the theme of NVM and OpenJDK is retro, the system itself is fast, but i want to encorage people to look at old software and learn how devs used to keep everything optimized unlike nowadays where you got crappy OS APIs that do the work for you and you end up writing a buggy codebase let alone a laggy crappy code like most companies unfortunatley do today (yes discord im looking at you!), so lets write clean code that works fast and wont crash (like my hopes) also ! savestates ! rember them !  
