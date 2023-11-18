import time
from subprocess import getoutput

class Tools:
    def timer(func):
        start = time.time()
        func()
        end = time.time()
        print(f"App ran in {(end - start)*1000}ms")

@Tools.timer
def runMachine():
    print(getoutput("bash -c ./app"))
