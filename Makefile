# Matheus Barcellos de Castro Cunha - 11208238
# Alexandre Brito Gomes - 11857323
# Alexandre Lima Palles Rocha - 11797038


FLAGS = -pthread -Wall -pedantic -g -D _POSIX_C_SOURCE=199309L -std=c++11
OBJS = ghost.o semaphore.o pacman.o campo.o game.o
EXEC = game
LDFLAGS = -lncurses -pthread


.PHONY: clean

all: game

game: $(OBJS)
	$(CXX) $(FLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean: 
	rm -f *.o *~ game

run: 
	./$(EXEC)
