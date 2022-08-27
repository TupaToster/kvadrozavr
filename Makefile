CXXFLAGS=-Wall -Wextra -Wpedantic -Wfloat-equal

all: kvadrat.exe

kvadrat.exe: main.o funcs.o
	g++ $(CXXFLAGS) main.o funcs.o -o kvadrat.exe

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

functions.o: funcs.cpp
	g++ $(CXXFLAGS) -c funcs.cpp

clean:
	rm -rf *.o kvadrat.exe*

.PHONY: clean