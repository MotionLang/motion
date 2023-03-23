import os
from testscripts import vartests

os.system("export PATH=$PATH:/workspaces/motionLang/build")

vartests.testvars()

def menu():
    print("1: Vartests")
    i = input("Choose: ")
    if i == 1:
        pass
