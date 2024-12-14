CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Werror -O2 -Wpedantic -pthread  -lm

LIBS =  -lgtest -lgcov
LINUX = -lrt -lpthread -lm -lsubunit
LFLAGS = -fprofile-arcs -ftest-coverage


SOURCE=$(wildcard s21*/*.tpp)
TEST_FILE=$(wildcard s21tests/*.cpp) #s21tests/test_map.cpp s21tests/test_set.cpp s21tests/test_multiset.cpp)


A_OUT=main
TEST_OUT=test
GCOV_OUT=gcov_test
TESTFLAG = -lgtest -lgtest_main

OS = $(shell uname -s)


test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(TEST_FILE) -g -o $(TEST_OUT) $(LIBS)
else
	$(CC) $(CFLAGS) $(TEST_FILE)  $(LIBS) $(LINUX) -g  -o $(TEST_OUT)
endif
	./$(TEST_OUT)


clean:
	rm -rf *.o coverage_info coverage_report *.a *.gcda *.gcno *.info *.gcov report $(GCOV_OUT) $(TEST_OUT) $(A_OUT) *.dSYM

style:
	@clang-format --style=Google -i  $(SOURCE) $(TEST_FILE)
	@echo "Don't panic! Clang is fine :)"


style_test:
	@clang-format --style=Google -n $(SOURCE) $(TEST_FILE)
	@echo "Don't panic! Clang is fine :)"



gcov_report: clean
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) $(TEST_FILE)  -o $(GCOV_OUT) $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) $(TEST_FILE)   $(LIBS) $(LINUX) -o $(GCOV_OUT)
endif
	./$(GCOV_OUT)
	mkdir report
	gcovr *.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o ./report/report.html
	open ./report/report.html

v: test
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./$(TEST_OUT)


docker_build:
	docker build -t vault:v1 .
	docker create -it --name matrix_cpp vault:v1

# Запускаем контейнер
docker_start:
	docker start -i matrix_cpp

docker_delete:
	docker rm matrix_cpp
	docker image rm vault:v1

GIT_MESSAGE = "delete Makefile in folders"

git-push: clean style
	@git pull origin develop
	@git add .
	@git commit -m $(GIT_MESSAGE)
	@git push -u origin develop
	@git status

ooo:
	git rm s21*/Makefile