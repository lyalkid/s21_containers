CC = gcc
CFLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra -pthread -lstdc++

OBJECT = $(subst .tpp,.o, stack.tpp)

TEST_FILES = test_stack.cpp
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
	ar rcs stack.a $^
	ranlib stack.a

test: clean
	$(CC) $(CFLAGS) $(TEST_FILES) $(TEST_LIBS) -g -o $(TEST_OUT)
	./$(TEST_OUT)

clean:
	rm -rf test