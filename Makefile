# ey.gellis@gmail.com
.PHONY: Main tests valgrind clean

CXX = g++
CXXFLAGS = -Wall -Wextra -g

LIBS = libalgorithms.a libdata_strct.a libgraph.a

PROG = Graph
PROG_SRC = main.cpp
PROG_OBJ = $(PROG_SRC:.cpp=.o)

TEST = TestGraph
TEST_SRC = tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

ALGO_OBJ = algorithms.o
DATA_OBJ = data_strct.o
GRAPH_OBJ = graph.o

DEPS = $(PROG_OBJ:.o=.d) $(TEST_OBJ:.o=.d) $(ALGO_OBJ:.d=.o) $(DATA_OBJ:.d=.o) $(GRAPH_OBJ:.d=.o)

Main: $(PROG)
	./$(PROG)

libalgorithms.a: $(ALGO_OBJ)
	ar rcs $@ $^

libdata_strct.a: $(DATA_OBJ)
	ar rcs $@ $^

libgraph.a: $(GRAPH_OBJ)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(PROG): $(PROG_OBJ) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $@ $(PROG_OBJ) $(LIBS)

$(TEST): $(TEST_OBJ) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJ) $(LIBS)

tests: $(TEST)
	./$(TEST)

valgrind: $(PROG)
	valgrind --leak-check=full --error-exitcode=1 ./$(PROG)

clean:
	rm -f $(PROG) $(TEST) $(PROG_OBJ) $(TEST_OBJ) $(LIBS) $(ALGO_OBJ) $(DATA_OBJ) $(GRAPH_OBJ) $(DEPS) *.d

-include $(DEPS)
