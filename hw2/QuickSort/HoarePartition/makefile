CC = g++
CFLAGS = -lm
EXE = main.exe
OBJS = main.o QuickSort.o 

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
