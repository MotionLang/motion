OBJS	= main.o chunk.o compiler.o debug.o flags.o memory.o object.o scanner.o table.o value.o vm.o
SOURCE	= main.c chunk.c compiler.c debug.c flags.c memory.c object.c scanner.c table.c value.c vm.c
HEADER	= common.h chunk.h compiler.h debug.h flags.h memory.h object.h scanner.h table.h value.h vm.h
OUT	= motion
CC	 = gcc
FLAGS	 = -g -c -Wall
VPATH = src include 
OBJDIR = src/obj

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	mv $(OBJS) src/obj
	mv $(OUT) bin
	clear
	bin/motion

release: $(OBJS)
	$(CC) -Ofast -g $(OBJS) -o $(OUT) $(LFLAGS)
	mv $(OBJS) src/obj
	mv $(OUT) bin
	clear
	bin/motion

main.o: main.c
	$(CC) $(FLAGS) src/main.c -std=c99

chunk.o: chunk.c
	$(CC) $(FLAGS) src/chunk.c -std=c99

compiler.o: compiler.c
	$(CC) $(FLAGS) src/compiler.c -std=c99

debug.o: debug.c
	$(CC) $(FLAGS) src/debug.c -std=c99

flags.o: flags.c
	$(CC) $(FLAGS) src/flags.c -std=c99

#errors.o: errors.c
#	$(CC) $(FLAGS) src/errors.c -std=c99

memory.o: memory.c
	$(CC) $(FLAGS) src/memory.c -std=c99

object.o: object.c
	$(CC) $(FLAGS) src/object.c -std=c99

scanner.o: scanner.c
	$(CC) $(FLAGS) src/scanner.c -std=c99

table.o: table.c
	$(CC) $(FLAGS) src/table.c -std=c99

value.o: value.c
	$(CC) $(FLAGS) src/value.c -std=c99

vm.o: vm.c
	$(CC) $(FLAGS) src/vm.c -std=c99


clean:
	rm -fvr $(OBJDIR)
	rm -fv bin/$(OUT)
	mkdir src/obj

fclean:
	rm -fvr *.o
exp:
	export PATH=${PATH}:/workspaces/motion/bin/

vgm:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes -v bin/motion

vgmq:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes -q bin/motion

vgh:
	valgrind --tool=helgrind -v bin/motion

vgc:
	valgrind --tool=callgrind --simulate-cache=yes --collect-atstart=no --instr-atstart=no bin/motion -r tests/testfiles/benchtests/strings.mn


safe: $(OBJS)
	$(CC) -g -fsanitize=address $(OBJS) -o $(OUT) $(LFLAGS)
	mv $(OBJS) src/obj
	mv $(OUT) bin

test:
	python3 tests/test.py