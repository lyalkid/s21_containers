CC = gcc
SOURCE = array.cpp
STATIC_LIB = array.a

OBJECTS = $(patsubst %.cpp,%.o, $(SOURCE))
CFLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra -pthread -lstdc++

TEST_OUT = test
TEST_FILE = test_array.cpp
TESTFLAG = -lgtest -lgtest_main

OS := $(shell uname -s)

ifeq ($(OS), Linux)
    TESTFLAG = -L/usr/local/lib -lgtest -lgtest_main -lsubunit -pthread -lstdc++
else
    TESTFLAG = -L/usr/local/lib -lgtest -lgtest_main -pthread -lstdc++
endif

all: clean $(STATIC_LIB) test gcov_report

$(STATIC_LIB): $(OBJECTS)
	@ar rcs $(STATIC_LIB) $^
	@ranlib $(STATIC_LIB)
	@echo "$@ created successfully."
	@rm -rf *.o

%.o: %.cpp
	@( $(CC) $(CFLAGS) -c $< -o $@ )

test: clean $(STATIC_LIB)
	@( $(CC) $(TESTFLAG) $(TEST_FILE) $(STATIC_LIB) -o $(TEST_OUT) )
	@( ./$(TEST_OUT) )
	@echo "Test executed 10/10."

clang:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -i *.cpp *.h */*.cpp
	@rm -rf .clang-format
	@echo "Don't panic! Clang is fine :)"

gcov_report: clean test
	@( $(CC) $(CFLAGS) --coverage -o gtest_test  $(TEST_FILE) $(SOURCE) $(TESTFLAG))
	@( chmod +x ./gtest_test )
	@( ./gtest_test )
	@  mkdir -p coverage_info
	@( lcov --capture --branch-coverage --directory . --output-file coverage_info/coverage.info --no-external --ignore-errors inconsistent,inconsistent)
	@( lcov --list coverage_info/coverage.info )
	@( genhtml coverage_info/coverage.info --output-directory coverage_report )
	@( open coverage_report/index.html )
	
clean:
	@( rm -rf *.o *.a $(STATIC_LIB) $(TEST_OUT) coverage_info coverage_report *.dSYM gtest_test *.gcno *.gcda *.out )
	@echo "Old version deleted!"

valgrind: test
	@( valgrind --tool=memcheck --leak-check=yes ./test )
	@echo "Valgrind completed."