CXX = clang++
OBJS = $(patsubst src/%.cpp, .objs/%.o, $(shell find src -type f -name "*.cpp" ))
EXECNAME = reversi

all: objdir $(EXECNAME)
	./$(EXECNAME)

.objs/%.o: src/%.cpp
	$(CXX) -c -o $@ $< -Wall -Werror -g -std=c++0x

$(EXECNAME): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

objdir:
	mkdir -p .objs/

clean:
	-rm -f .objs/*.o $(EXECNAME)

