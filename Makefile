CXX = g++
TARGET = main
SRC = $(wildcard *.cpp)
OBJECT = $(patsubst %.cpp, %.o, ${SRC})

CXXFLAGS = -c -Wall 

${TARGET}: ${OBJECT}
	${CXX} -o $@ $^

%.o: %.cpp
	${CXX} ${CXXFLAGS} $< -o $@

PHONY: clean
clean:
	rm -f *.o ${TARGET}