FLAGS = -pthread -Wall -pedantic -g -D _POSIX_C_SOURCE=199309L
OBJS = ghost.o semaphore.o pacman.o
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

# appname := pacman

# CXX := clang++
# CXXFLAGS := -std=c++11 -fcommon

# srcfiles := $(shell find . -name "*.cpp")
# objects  := $(patsubst %.cpp, %.o, $(srcfiles))

# all: $(appname)

# $(appname): $(objects)
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

# depend: .depend

# .depend: $(srcfiles)
# 	rm -f ./.depend
# 	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

# clean:
# 	rm -f $(objects)

# dist-clean: clean
# 	rm -f *~ .depend

# include .depend