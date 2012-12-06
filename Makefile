CXX = g++								# compiler
CXXFLAGS = -g -Wall -MMD			# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS = Card.o CardPile.o Deck.o Trick.o Player.o HumanPlayer.o SmartPlayer.o RandomPlayer.o p4driver.o 		# object files forming executable
EXECS = Hearts							# executable name

DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"

.PHONY : all clean

all : ${EXECS}

${EXECS} : ${OBJECTS}				# link step
	${CXX} ${CXXFLAGS} $^ -o $@

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}
