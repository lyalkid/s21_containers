CC=g++
#<<<<<<< HEAD
CFLAGS=-std=c++17 -Wall -Wextra -Werror
LIBS =  -lgtest -lgcov
LINUX = -lrt -lpthread -lm -lsubunit
LFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)
A_OUT=main
clang_file="---\nBasedOnStyle: Google\nIndentWidth: 4\nColumnLimit: 110\n"

compile:
	@g++ main.cpp -o $(A_OUT)

compileg:
	@g++ main.cpp -g -o $(A_OUT)


run: style compile
	./$(A_OUT)

test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) tests/*.cc -o unit_tests $(LIBS)
else
	$(CC) $(CFLAGS) tests/*.cc -o unit_tests $(LIBS) $(LINUX)
endif
	./unit_tests


gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) tests/*.cc  -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) tests/*.cc  -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	mkdir report
	gcovr *.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o ./report/report.html
	open ./report/report.html


cp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp *.h *.tpp

v: compileg
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./main


clean:
	rm -rf .clang-format *.o *.a *.gcda *.gcno *.info *.gcov report gcov_test test.out $(A_OUT) 

style:
	@clang-format --style=Google -i *.h *.cpp */*.h */*.cpp *.tpp 
	@echo "Don't panic! Clang is fine :)"
	

style_test:
	@clang-format --style=Google -n *.h *.cpp */*.h */*.cpp
	@echo "Don't panic! Clang is fine :)"


clang:
	@touch .clang-format
	@echo $(clang_file) >> .clang-format
	@clang-format -i *.h
	@clang-format -n *.h
	@rm -rf .clang-format


#valg: clean test
#	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./matrix_test
#
#valgrind: clean test
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks_log.txt ./matrix_test
#	echo --- Valgrind summary --- && cat leaks_log.txt | grep 'total heap usage' && cat leaks_log.txt | grep 'ERROR SUMMARY'

# Собираем docker image с тегом 'v1' на основании dockerfile и создаем контейнер
docker_build:
	docker build -t vault:v1 .
	docker create -it --name matrix_cpp vault:v1

# Запускаем контейнер
docker_start:
	docker start -i matrix_cpp

docker_delete:
	docker rm matrix_cpp
	docker image rm vault:v1


# =======
# ADD_LIB=-lgtest -lm
# FLAGS=-std=c++17 -Wpedantic -Werror -Wextra -Wall
# GCOV=--coverage
# ASAN=-fsanitize=address -static-libasan -g
# OS=$(shell uname -s)

# ifeq ($(OS), Linux)
# 	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all
# 	OPEN_CMD=xdg-open
# else ifeq ($(OS), Darwin)
# 	LEAK_CHECK=leaks -atExit --
# 	OPEN_CMD=open
# endif

# main: clean
# 	g++ main.cpp -o main
# 	./main

# main_asan: clean
# 	g++ $(ASAN) main.cpp -o main
# 	./main

# main_leaks: clean
# 	g++ main.cpp -o main
# 	$(LEAK_CHECK) ./main

# test: clean
# 	$(CC) $(FLAGS) tests/map_test.cpp -o test $(ADD_LIB)
# 	./test

# leaks: clean
# 	$(CC) $(FLAGS) tests/vector_test.cpp -o test $(ADD_LIB) 
# 	$(LEAK_CHECK) ./test

# asan: clean
# 	$(CC) $(FLAGS) $(ASAN) tests/*.cpp -o test $(ADD_LIB) 
# 	./test

# gcov_report:
# 	$(CC) $(FLAGS) $(GCOV) tests/vector_test.cpp -o gcov_test $(ADD_LIB)
# 	./gcov_test
# 	lcov -c -d . --no-external -o gcov_test.info
# 	genhtml -o report gcov_test.info
# 	chmod 777 report/*
# 	$(OPEN_CMD) report/index.html
# 	rm *.gcda *.gcno *.info gcov_test

# clang:
# 	cp ../materials/linters/.clang-format .
# 	clang-format -i *.h tests/*.cpp
# 	rm -rf .clang-format

# clean:
# 	@rm -rf \
# 	*.o \
# 	main \
# 	test \
# 	report

# # .PHONY: 
# >>>>>>> racquebu



# version 2
#CC = gcc
#SOURCE = $(wildcard *.tpp)
#STATIC_LIB = map.a
#
#OBJECTS = $(patsubst %.tpp,%.o, $(SOURCE))
#CFLAGS = -std=c++17 -O2 -pedantic -Wall -Werror -Wextra -pthread -lstdc++ -lm
#
#TEST_OUT = test
#TEST_FILE = test_map/test_map.cpp
#TESTFLAG = -lgtest -lgtest_main
#
#OS := $(shell uname -s)
#
#ifeq ($(OS), Linux)
#    TESTFLAG = -L/usr/local/lib -pedantic  -Wall -Werror -Wextra -lgtest -lgtest_main -lsubunit -pthread -lstdc++ -lm
#else
#    TESTFLAG = -L/usr/local/lib -lgtest -lgtest_main -pthread -lstdc++ -lm
#endif
#
#all: clean test valgrind
#
#$(STATIC_LIB): $(OBJECTS)
#	@ar rcs $(STATIC_LIB) $^
#	@ranlib $(STATIC_LIB)
#	@echo "$@ created successfully."
#	@rm -rf *.o
#
#%.o: %.tpp
#	@( $(CC) $(CFLAGS) -c $< -o $@ )
#
#
#
#compile:
#	@g++ main.cpp $(SOURCE) -o $(A_OUT)
#
#compileg:
#	@g++ main.cpp $(SOURCE)	 -g -o $(A_OUT)
#
#run: style compile
#	./$(A_OUT)
#
#test: clean
#	@( $(CC)  $(TEST_FILE) $(TESTFLAG) -o $(TEST_OUT) )
#	@( ./$(TEST_OUT) )
#	@echo "Test executed 10/10."
#
#
#
#
##gcov_report:
##ifeq ($(OS), Darwin)
##	$(CC) $(CFLAGS) $(LFLAGS) tests/*.cc  -o test.out $(LIBS)
##else
##	$(CC) $(CFLAGS) $(LFLAGS) tests/*.cc  -o test.out $(LIBS) $(LINUX)
##endif
##	./test.out
##	mkdir report
##	gcovr *.gcda
##	gcovr -b
##	gcovr
##	gcovr --html-details -o ./report/report.html
##	open ./report/report.html
#
#
#
##valgrind: test
##	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./unit_tests
#
#
#clean:
#	rm -rf .clang-format *.o *.a *.gcda *.gcno *.info *.gcov report gcov_test test.out $(A_OUT)
#
#style:
#	@clang-format --style=Google -i *.h *.cpp */*.h */*.cpp *.tpp
#	@echo "Don't panic! Clang is fine :)"
#
#
#style_test:
#	@clang-format --style=Google -n *.h *.cpp */*.h */*.cpp
#	@echo "Don't panic! Clang is fine :)"
#
#
#clang:
#	@touch .clang-format
#	@echo $(clang_file) >> .clang-format
#	@clang-format -i *.h
#	@clang-format -n *.h
#	@rm -rf .clang-format
#
#
##valg: clean test
##	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./matrix_test
##
##valgrind: clean test
##	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks_log.txt ./matrix_test
##	echo --- Valgrind summary --- && cat leaks_log.txt | grep 'total heap usage' && cat leaks_log.txt | grep 'ERROR SUMMARY'
#
## Собираем docker image с тегом 'v1' на основании dockerfile и создаем контейнер
#docker_build:
#	docker build -t vault:v1 .
#	docker create -it --name matrix_cpp vault:v1
#
## Запускаем контейнер
#docker_start:
#	docker start -i matrix_cpp
#
#docker_delete:
#	docker rm matrix_cpp
#	docker image rm vault:v1
#
#
## =======
## ADD_LIB=-lgtest -lm
## FLAGS=-std=c++17 -Wpedantic -Werror -Wextra -Wall
## GCOV=--coverage
## ASAN=-fsanitize=address -static-libasan -g
## OS=$(shell uname -s)
#
## ifeq ($(OS), Linux)
## 	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all
## 	OPEN_CMD=xdg-open
## else ifeq ($(OS), Darwin)
## 	LEAK_CHECK=leaks -atExit --
## 	OPEN_CMD=open
## endif
#
## main: clean
## 	g++ main.cpp -o main
## 	./main
#
## main_asan: clean
## 	g++ $(ASAN) main.cpp -o main
## 	./main
#
## main_leaks: clean
## 	g++ main.cpp -o main
## 	$(LEAK_CHECK) ./main
#
## test: clean
## 	$(CC) $(FLAGS) tests/map_test.cpp -o test $(ADD_LIB)
## 	./test
#
## leaks: clean
## 	$(CC) $(FLAGS) tests/vector_test.cpp -o test $(ADD_LIB)
## 	$(LEAK_CHECK) ./test
#
## asan: clean
## 	$(CC) $(FLAGS) $(ASAN) tests/*.cpp -o test $(ADD_LIB)
## 	./test
#
## gcov_report:
## 	$(CC) $(FLAGS) $(GCOV) tests/vector_test.cpp -o gcov_test $(ADD_LIB)
## 	./gcov_test
## 	lcov -c -d . --no-external -o gcov_test.info
## 	genhtml -o report gcov_test.info
## 	chmod 777 report/*
## 	$(OPEN_CMD) report/index.html
## 	rm *.gcda *.gcno *.info gcov_test
#
## clang:
## 	cp ../materials/linters/.clang-format .
## 	clang-format -i *.h tests/*.cpp
## 	rm -rf .clang-format
#
## clean:
## 	@rm -rf \
## 	*.o \
## 	main \
## 	test \
## 	report
#
## # .PHONY:
## >>>>>>> racquebu