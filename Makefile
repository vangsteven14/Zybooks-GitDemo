all: main

CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')

main: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug res*
unit1:
	g++ tests/test.cpp main.cpp -o result1 && ./result1

unit2:
	g++ tests/test2.cpp main.cpp -o result2 && ./result2

unit3: 
	g++ tests/test3.cpp main.cpp -o result3 && ./result3

unit4:
	g++ tests/test4.cpp main.cpp -o result4 && ./result4
