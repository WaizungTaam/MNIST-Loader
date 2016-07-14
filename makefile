CC=g++
FLAG=-std=c++11
PATH_SRC=./src/
PATH_TEST=./test/

all: mnist_test.o

mnist_test.o: $(PATH_SRC)mnist.h $(PATH_SRC)mnist.cc $(PATH_TEST)mnist_test.cc
	$(CC) $(FLAG) $(PATH_SRC)mnist.h $(PATH_SRC)mnist.cc $(PATH_TEST)mnist_test.cc -o mnist_test.o

clean:
	rm *.o