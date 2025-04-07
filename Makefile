CXX = g++
CFLAGS = -Wall -Wextra -g
CXXFLAGS = -Wall -Wextra -g

PROG = Graph
PROG_SRC = main.cpp

TEST = test_runner
TEST_SRC = tests.cpp

Main: $(PROG)
	./Main

$(PROG): $(PROG_SRC)
	$(CXX) $(CXXFLAGS) $(PROG_SRC) -o $(PROG)

tests: $(TEST)
	./$(TEST)

$(TEST): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST)

valgrind: $(PROG)
	valgrind --leak-check=full --error-exitcode=1 ./$(PROG)

clean:
	rm -f $(PROG) $(TEST) *.o *.a

.PHONY: Main tests valgrind clean
