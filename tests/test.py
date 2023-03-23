import os
from testscripts import vartests

os.system("export PATH=$PATH:/workspaces/motionLang/build")

vartests.testvars()
