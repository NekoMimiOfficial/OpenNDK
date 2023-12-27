# Nyani binary struct  

```
{0 -> 99}:                          metadata
{86}:                               temp address
{100 -> (Max-0x66)}:                program memory
{(Max-0x66) -> Max}:                video ram
```

## metadata  
regualar data about bin file like the "NekoASm" header and creation date  

## temp address  
saves temp data like jump locations and return values from components and ALU  

## program memory  
stores the full program and its data  

## vram (video ram)  
stores video data and/or video buffers with data like characters or pallet colors (pallet can contain upto 0xFFFF values)
