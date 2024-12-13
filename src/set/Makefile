CC=g++

CFLAGS=-std=c++17 -Wall -Wextra -Werror
LIBS =  -lgtest -lgcov
LINUX = -lrt -lpthread -lm -lsubunit
LFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)
A_OUT=main
clang_file="---\nBasedOnStyle: Google\nIndentWidth: 4\nColumnLimit: 110\n"
TEST_OUT=unit_tests
GCOV_OUT=gcov_test
TESTS=$(wildcard testSet.cpp)
c:
	@g++  main.cpp 
git-push: clean style
	@git pull
	@git add .
	@git commit -m "set is done "
	@git push -u origin fearowpi
	@git status

test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(TESTS)  -o $(TEST_OUT) $(LIBS)
else
	$(CC) $(CFLAGS) $(TESTS)  $(LIBS) $(LINUX)  -o $(TEST_OUT)
endif
	./$(TEST_OUT)

clean:
	rm -rf .clang-format a.out *.o *.a *.gcda *.gcno *.info *.gcov report $(GCOV_OUT) $(TEST_OUT) $(A_OUT) *.dSYM

style:
	@clang-format --style=Google -i  *.cpp *.h 
	@echo "Don't panic! Clang is fine :)"
