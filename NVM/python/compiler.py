from NekoMimi import colourimi as cm
import sys

class Pallet:
    text = "#DDDDDD"
    text2 = "#888888"
    catBlue = "#799DDB"
    catRed = "#F38BA8"
    catOrange = "#F3B993"
    catGreen = "#A2DCAA"
    catPurr = "#C6A1F0"

factory = cm.colourFactory()

def kprint(text, col=Pallet.text):
    factory.text = text
    factory.colour = col
    factory.cinit()
    factory.cprint()
    return

def main():
    if len(sys.argv) < 2:
        kprint("Please supply a source file", Pallet.catRed)
        exit(1)

if __name__ == '__main__':
    main()
