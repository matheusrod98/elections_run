CC = g++

ifeq ($(cc), GCC)
CC = g++
endif

ifeq ($(cc), CLANG)
CC = clang
endif

CFLAGS = -Wall -std=c++98

OBJECTS = Estadual.o Nacional.o main.o moving_average.o

EXEC = first_assignment

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

clean-all:
	rm -f *.o first_assignment
