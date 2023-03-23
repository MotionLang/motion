import subprocess
import os
print("Var Tests loaded")

def testvars():
    """Testing variables"""
    directory = '/workspaces/motionLang/tests/testfiles/vartests'
    for i in os.listdir(directory):
        f = os.path.join(directory, i)
        # checking if it is a file
        if os.path.isfile(f):
            f = f.replace("/workspaces/motionLang/", '')
            cmd = "motion " + f
            res = subprocess.check_output(cmd, shell=True)
            print(res)