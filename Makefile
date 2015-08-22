CC=g++
CPPFLAGS  = -std=c++11 -g -Wextra -Wall
RM=rm -f

SRCS=IntMatrix.cpp IntMatrixDriver.cpp 
OBJS=$(subst .cc,.o,$(SRCS))

MAIN = IntMatrixMainDriver

default: $(MAIN)

IntMatrixMainDriver: $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
	
IntMatrix: IntMatrix.o
	
IntMatrix.o: IntMatrix.cpp IntMatrix.h

IntMatrixDriver.o: IntMatrixDriver.cpp IntMatrix.o


clean:
	$(RM) *.o *~ $(MAIN)