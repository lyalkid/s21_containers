CC = gcc
CFLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra -pthread -lstdc++

OBJECT = $(subst .tpp,.o, queue.tpp)

TEST_FILES = test_queue.cpp
TEST_OUT = test

OS := $(shell uname -s)

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
	TEST_LIBS = -lgtest -lgtest_main -lsubunit -lrt -lm -pthread -lstdc++
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
	TEST_LIBS = -L/usr/local/lib -lgtest -lgtest_main -pthread -lstdc++
endif

stack.a: $(OBJECT)
	ar rcs queue.a $^
	ranlib queue.a

test: clean
	$(CC) $(CFLAGS) $(TEST_FILES) $(TEST_LIBS) -g -o $(TEST_OUT)
	./$(TEST_OUT)

gcov_report: clean
	$(CC) $(CFLAGS) --coverage -o gtest_test $(TEST_FILES) $(TEST_LIBS)
	chmod +x ./gtest_test
	./gtest_test
	lcov --capture --branch-coverage --directory . --output-file ./coverage.info --no-external --ignore-errors inconsistent,inconsistent
	lcov --list ./coverage.info
	genhtml ./coverage.info --output-directory ./coverage_report
	$(OPEN_CMD) ./coverage_report/index.html

clean:
	rm -rf coverage_info coverage_report *.dSYM gtest_test *.gcno *.gcda *.out coverage.info test leaks_log.txt

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks_log.txt ./test
	echo --- Valgrind summary --- && cat leaks_log.txt | grep 'total heap usage' && cat leaks_log.txt | grep 'ERROR SUMMARY'
