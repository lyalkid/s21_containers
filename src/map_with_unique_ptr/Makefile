CC=g++

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

