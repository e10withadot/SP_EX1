# ey.gellis@gmail.com
.PHONY: Main tests valgrind clean

CXX = g++
CXXFLAGS = -Wall -Wextra -g

PROG = Graph
PROG_SRC = main.cpp
PROG_OBJ = $(PROG_SRC:.cpp=.o)

TEST = TestGraph
TEST_SRC = tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

LIB = libgraph.a
LIB_SRC = algorithms.cpp data_strct.cpp graph.cpp
LIB_OBJ = $(LIB_SRC:.cpp=.o)

Main: $(PROG)
	./$(PROG)

$(LIB): $(LIB_OBJ)
	ar -rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROG): $(LIB) $(PROG_OBJ)
	$(CXX) $(CXXFLAGS) $(PROG_OBJ) -L. -lgraph -o $@

$(TEST): $(LIB) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -L. -lgraph -o $@

tests: $(TEST)
	./$(TEST)

valgrind: $(PROG)
	valgrind --leak-check=full --error-exitcode=1 ./$(PROG)

clean:
	rm -f $(PROG) $(TEST) $(LIB) $(PROG_OBJ) $(TEST_OBJ) $(LIB_OBJ)
