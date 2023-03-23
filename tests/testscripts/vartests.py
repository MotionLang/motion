import subprocess
import os
print("Var Tests loaded")

def testvars():
    """Testing variables"""
    directory = '/workspaces/motionLang/tests/testfiles/vartests'
    for filename in os.listdir(directory):
        f = os.path.join(directory, filename)
        # checking if it is a file
        if os.path.isfile(f):
            f = f.replace("/workspaces/motionLang/", '')
            print(f)
            os.system("motion " + f)
