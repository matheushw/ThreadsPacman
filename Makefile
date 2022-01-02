# Matheus Barcellos de Castro Cunha - 11208238
# Botem os nomes aqui!!

FLAGS = -pthread -Wall -pedantic -g -D _POSIX_C_SOURCE=199309L -std=c++11
OBJS = ghost.o semaphore.o pacman.o campo.o
EXEC = pacman

.PHONY: clean

all: pacman

pacman: $(OBJS)
	$(CXX) $(FLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean: 
	rm -f *.o *~ pacman

run: 
	./$(EXEC)
