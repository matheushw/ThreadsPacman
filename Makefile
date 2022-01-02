# Matheus Barcellos de Castro Cunha - 11208238
# Botem os nomes aqui!!

FLAGS = -Wall -pedantic -g -D _POSIX_C_SOURCE=199309L -std=c++11 -lcurses
OBJS = ghost.o semaphore.o pacman.o campo.o game.o
EXEC = game

.PHONY: clean

all: game

game: $(OBJS)
	$(CXX) $(FLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean: 
	rm -f *.o *~ game

run: 
	./$(EXEC)
