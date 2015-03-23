CC=g++
MAKE=make
INCLUDE=include
GTEST_LOC=../../Common/gtest-1.7.0

default:
	$(CC) -I$(INCLUDE) -Wall -c src/*.cpp
	ar -cvq libspeedy-strs.a *.o
	$(MAKE) example
	$(MAKE) clean

example:
	$(CC) -o example *.o

gtest:
	$(CC) -I$(GTEST_LOC)/include -Wall -c test/*.cpp
	$(CC) -pthread -o all_tests basic_test.o $(GTEST_LOC)/make/gtest.a
	$(MAKE) clean

clean:
	rm *.o
