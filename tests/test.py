import subprocess
import os

numtests = 0
passed = 0
failed = 0

def test(path, expected):
    """Test a path"""
    global numtests
    global passed
    global failed
    os.system(
        "export PATH=$PATH:/workspaces/motionLang/bin")
    cmd = "bin/motion -r " + path
    out = subprocess.check_output(cmd, shell=True, universal_newlines=True)
    print(out)
    numtests = numtests + 1
    if out.rstrip("\n") == expected:
        passed = passed + 1
    else:
        failed = failed + 1

def bench(path):
    """Benchmark a path"""
    global numtests
    os.system(
        "export PATH=$PATH:/workspaces/motionLang/bin")
    cmd = "bin/motion -r " + path
    out = subprocess.check_output(cmd, shell=True, universal_newlines=True)
    print(out)
    numtests = numtests + 1


def stats():
    """"Output stats"""
    print(str(numtests) + " Test(s)")
    print(str(passed) + " Passed")
    print(str(failed) + " Failed")
    input("Press Enter to continue...")
    menu()

def benchstats():
    print(str(numtests) + " Test(s)")
    input("Press Enter to continue...")
    menu()

def vartests():
    """Run variable tests"""       
    test("tests/testfiles/vartests/vartest1.mtn", "nil")
    test("tests/testfiles/vartests/vartest2.mtn", "1")
    test("tests/testfiles/vartests/vartest3.mtn", "10")


def booltests():
    """Run boolean tests"""
    test("tests/testfiles/booltests/testTrue.mtn", "true")
    test("tests/testfiles/booltests/testFalse.mtn", "false")
    test("tests/testfiles/booltests/testNil.mtn", "nil")
    test("tests/testfiles/booltests/testNot.mtn", "false")

def compareTests():
    """Run comparison tests"""
    test("tests/testfiles/compareTests/testGreater.mtn", "true")
    test("tests/testfiles/compareTests/testGreaterEqual1.mtn", "true")
    test("tests/testfiles/compareTests/testGreaterEqual2.mtn", "true")
    test("tests/testfiles/compareTests/testLess.mtn", "true")
    test("tests/testfiles/compareTests/testLessEqual.mtn", "true")
    test("tests/testfiles/compareTests/testLessEqual2.mtn", "true")

def ifTests():
    test("tests/testfiles/ifTests/ifTrue.mtn", "success")
    test("tests/testfiles/ifTests/ifFalse.mtn", "")
    test("tests/testfiles/ifTests/ifElseTrue.mtn", "if")
    test("tests/testfiles/ifTests/ifElseFalse.mtn", "else")

def benchtests():
    bench("tests/testfiles/benchtests/binary_trees.mn")
    bench("tests/testfiles/benchtests/zoo.mn")
    bench("tests/testfiles/benchtests/strings.mn")



def menu():
    """Main menu"""
    subprocess.Popen("export PATH=$PATH:/workspaces/motionLang/build", shell=True)
    print("0: Exit")
    print("1: Var Tests")
    print("2: Boolean Tests")
    print("3: Comparison Tests")
    print("4: 'if' tests")
    
    print("#: Benchmark Tests")
    print("@: All Tests")


    to_run = input("Choose: ")
    if to_run == "0":
        os._exit(0)

    elif to_run == "#":
        benchtests()
        stats()

    elif to_run == "@":
        vartests()
        booltests()
        compareTests()
        ifTests()
        stats()

    elif to_run == "1":
        vartests()
        stats()

    elif to_run == "2":
        booltests()
        stats()
    elif to_run == "3":
        compareTests()
        stats()
    elif to_run == "4":
        ifTests()
        stats()

menu()