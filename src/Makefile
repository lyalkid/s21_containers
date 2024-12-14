CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Werror -O2 -Wpedantic -pthread  -lm

LIBS =  -lgtest
LINUX = -lrt -lpthread -lm -lsubunit
LFLAGS = -fprofile-arcs -ftest-coverage


SOURCE=$(wildcard s21*/*.tpp s21*/*.h)
TEST_FILE=$(wildcard s21tests/*.cpp)


A_OUT=main
TEST_OUT=test
GCOV_OUT=gcovr/gcov_test
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
	rm -rf gcovr *.o coverage_info coverage_report *.a *.gcda *.gcno *.info *.gcov report $(GCOV_OUT) $(TEST_OUT) $(A_OUT) *.dSYM

style:
	@clang-format --style=Google -i  $(SOURCE) $(TEST_FILE) *.h
	@echo "Don't panic! Clang is fine :)"
	#clang-format -i $(SOURCE) $(TEST_FILE) *.h


style_test:
	@clang-format --style=Google -n $(SOURCE) $(TEST_FILE) *.h
	@echo "Don't panic! Clang is fine :)"



gcov_report: clean
	mkdir -p gcovr
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) --coverage  $(LFLAGS) $(TEST_FILE)  -o $(GCOV_OUT) $(LIBS)
else
	$(CC) $(CFLAGS) --coverage  $(LFLAGS) $(TEST_FILE)   $(LIBS) $(LINUX) -o $(GCOV_OUT)
endif
	#$(CC) --coverage $(CFLAGS) $(TEST_FLAGS) $(SOURCE) tests/test.cpp -o ./gcovr/gtest_test
	chmod +x ./$(GCOV_OUT)
	./$(GCOV_OUT)
	lcov --capture --branch-coverage --directory . --output-file ./gcovr/coverage.info --no-external --ignore-errors inconsistent,inconsistent,mismatch --exclude '*/s21tests/*'
	lcov --list ./gcovr/coverage.info
	genhtml ./gcovr/coverage.info --output-directory ./gcovr/coverage_report
	open ./gcovr/coverage_report/index.html



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

GIT_MESSAGE = "final"

git-push: clean style
	@git pull origin develop
	@git add .
	@git commit -m $(GIT_MESSAGE)
	@git push -u origin develop
	@git status

ooo:
	git rm s21*/Makefile