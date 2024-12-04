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
TESTS=$(wildcard tests/*.cpp)
compile:
	@g++ main.cpp -o $(A_OUT)

compileg:
	@g++ main.cpp -g -o $(A_OUT)


run: style compile
	./$(A_OUT)

test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(TESTS) -g -o $(TEST_OUT) $(LIBS)
else
	$(CC) $(CFLAGS) $(TESTS)  $(LIBS) $(LINUX)  -o $(TEST_OUT)
endif
	./$(TEST_OUT)


gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) $(TESTS)  -o $(GCOV_OUT) $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) $(TESTS)   $(LIBS) $(LINUX) -o $(GCOV_OUT)
endif
	./$(GCOV_OUT)
	mkdir report
	gcovr *.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o ./report/report.html
	open ./report/report.html


cp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp *.h *.tpp

v: compileg test
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./$(TEST_OUT)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./$(A_OUT)

#
#vt: test
#	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./$(TEST_OUT)


clean:
	rm -rf .clang-format *.o *.a *.gcda *.gcno *.info *.gcov report $(GCOV_OUT) $(TEST_OUT) $(A_OUT) *.dSYM

style:
	@clang-format --style=Google -i  *.cpp */*.h */*.cpp */*.tpp
	@echo "Don't panic! Clang is fine :)"


style_test:
	@clang-format --style=Google -n *.cpp */*.h */*.cpp */*.tpp
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

GIT_MESSAGE = "refactor"

git-push: style
	@git add ../..
	@git commit -m $(GIT_MESSAGE)
	@git push -u origin sionapae

