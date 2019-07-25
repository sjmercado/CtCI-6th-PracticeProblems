CC = g++
CFLAGS = -std=c++11 -g -Wall
DEPS = SLL.hpp
OBJS = SLL.o

# Create object files
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

# Create executable files
q01: q01_removeDuplicates.o SLL.o
	$(CC) $(CFLAGS) -o q01 q01_removeDuplicates.o SLL.o

q02: q02_findKthToLast.o SLL.o
	$(CC) $(CFLAGS) -o q02 q02_findKthToLast.o SLL.o

q03: q03_deleteMiddleNode.o SLL.o
	$(CC) $(CFLAGS) -o q03 q03_deleteMiddleNode.o SLL.o


test: test.o SLL.o 
	$(CC) $(CFLAGS) -o test test.o SLL.o

.PHONY = clean

clean: 
	del -f *.o *.exe