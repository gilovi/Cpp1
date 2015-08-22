CC=g++
CPPFLAGS  = c++11 -g -Wextra -Wall
RM=rm -f

SRCS=IntMatrix.cpp IntMatrixDriver.cpp 
OBJS=$(subst .cc,.o,$(SRCS))

MAIN = IntMatrixMainDriver

default: $(MAIN)

IntMatrixMainDriver: $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
	
IntMatrix: IntMatrix.o
	
IntMatrix.o: IntMatrix.cpp IntMatrix.h
# generates c or o?
IntMatrixDriver.o: IntMatrix.o
	#what to do?

clean:
        $(RM) *.o *~ $(MAIN)