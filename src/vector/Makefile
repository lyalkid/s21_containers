CC = gcc
SOURCE = vector.tpp
STATIC_LIB = vector.a

OBJECTS = $(patsubst %.tpp,%.o, $(SOURCE))
CFLAGS = -std=c++17 -O2 -pedantic -Wall -Werror -Wextra -pthread -lstdc++

TEST_OUT = test
TEST_FILE = test_vector.cpp
TESTFLAG = -lgtest -lgtest_main

OS := $(shell uname -s)

ifeq ($(OS), Linux)
    TESTFLAG = -L/usr/local/lib -pedantic  -Wall -Werror -Wextra -lgtest -lgtest_main -lsubunit -pthread -lstdc++ -lm
else
    TESTFLAG = -L/usr/local/lib -lgtest -lgtest_main -pthread -lstdc++ -lm
endif

all: clean test valgrind

$(STATIC_LIB): $(OBJECTS)
	@ar rcs $(STATIC_LIB) $^
	@ranlib $(STATIC_LIB)
	@echo "$@ created successfully."
	@rm -rf *.o

%.o: %.tpp
	@( $(CC) $(CFLAGS) -c $< -o $@ )

test: clean 
	@( $(CC)  $(TEST_FILE) $(TESTFLAG) -g -o $(TEST_OUT) )
	@( ./$(TEST_OUT) )
	@echo "Test executed 10/10."

clang:
	@cp ../../materials/linters/.clang-format .clang-format
	@clang-format -i *.tpp *.h *.cpp
	@rm -rf .clang-format
	@echo "Don't panic! Clang is fine :)"

gcov_report: clean test
	@( $(CC) $(CFLAGS) $(TEST_FILE) --coverage -o gtest_test  $(TESTFLAG))
	@( chmod +x ./gtest_test )
	@( ./gtest_test )
	@  mkdir -p coverage_info
	@( lcov --capture --directory . --rc lcov_branch_coverage=1 --output-file coverage_info/coverage.info )
	@( lcov --list coverage_info/coverage.info )
	@( genhtml coverage_info/coverage.info --output-directory --rc lcov_branch_coverage=1 coverage_report)
	@( open coverage_report/index.html )
	
clean:
	@( rm -rf *.o *.a $(STATIC_LIB) $(TEST_OUT) coverage_info coverage_report *.dSYM gtest_test *.gcno *.gcda *.out )
	@echo "Old version deleted!"

valgrind: test
	@( valgrind --tool=memcheck --leak-check=yes ./$(TEST_OUT) )
	@echo "Valgrind completed."