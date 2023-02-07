CXX 	= g++
# CXX 	= clang++
CFLAGS 	= -Wall -std=c++11 -g
# SOURCES = main.cpp Game.cpp Player.cpp
# HEADERS = Game.h Player.h
INCDIR = inc
OBJDIR = obj

# TARGET: DEPENDENCIES
#	ACTION

baccarat: main.o Game.o Player.o Deck.o
	$(CXX) main.o Game.o Player.o Deck.o -o baccarat

main.o: main.cpp
	$(CXX) -c $(CFLAGS) main.cpp

Game.o: $(INCDIR)/Game.h Game.cpp
	$(CXX) -c $(CFLAGS) Game.cpp

Player.o: $(INCDIR)/Player.h Player.cpp
	$(CXX) -c $(FLAGS) Player.cpp

Deck.o: $(INCDIR)/Deck.h Deck.cpp
	$(CXX) -c $(FLAGS) Deck.cpp

clean:
	rm -f baccarat
	rm -f *.o
