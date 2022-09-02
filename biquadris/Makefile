CXX = g++
CXXFLAGS = -std=c++14 -g -Werror=vla -Wall -MMD
EXEC = biquadris
OBJECTS = main.o board.o block.o jblock.o lblock.o iblock.o sblock.o oblock.o zblock.o tblock.o coordinate.o tile.o noblock.o interface.o one.o two.o zero.o level.o three.o controller.o four.o onebyone.o

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean