CC = g++
C11 = -std=c++11
CFLAGS = -lm
EXE = ASA.exe
OBJS = ASA.o
all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(C11) $(CFLAGS) -o $(EXE) $(OBJS)

%.o : %.cc
	$(CC) $(C11) $(CFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
