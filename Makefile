SRCDIR = src
OBJDIR = .obj
EXECNAME = reversi
LDFLAGS =
CXXFLAGS = -Wall -Wextra -g -std=c++0x
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
DEP = $(OBJ:.o=.d)

default: objfolder $(EXECNAME)
	./$(EXECNAME)

$(EXECNAME): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

objfolder:
	mkdir -p $(OBJDIR)

-include $(DEP)
$(OBJDIR)/%.d: $(SRCDIR)/%.cpp
	$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	-rm -f $(OBJ) $(EXECNAME)
	-rm -f $(DEP)

