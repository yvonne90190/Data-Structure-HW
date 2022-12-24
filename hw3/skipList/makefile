CC = g++
CFLAGS = -lm
EXE = skipList.exe
OBJS = skipList.o
all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

%.o : %.cc
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
