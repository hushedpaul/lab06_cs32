# Makefile

CXX=clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = lab05test1

all : ${BINARIES}

lab05test1: lab05test1.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab05test1

clean:
	/bin/rm -f ${BINARIES} *.o
