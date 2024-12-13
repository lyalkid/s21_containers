CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Werror -O2 -Wpedantic -pthread -lstdc++ -lm

LIBS =  -lgtest -lgcov
LINUX = -lrt -lpthread -lm -lsubunit
LFLAGS = -fprofile-arcs -ftest-coverage


SOURCE=$(wildcard s21*/*.tpp)
TEST_FILE=$(wildcard s21tests/test_main.cpp s21tests/test_list.cpp) #s21tests/test_map.cpp s21tests/test_set.cpp s21tests/test_multiset.cpp)


STATIC_LIB=s21_containers.a
STATIC_LIB_PLUS=s21_containers_plus.a

A_OUT=main
TEST_OUT=test
GCOV_OUT=gcov_test
TESTFLAG = -lgtest -lgtest_main

OS = $(shell uname -s)


# ifeq ($(OS), Linux)
#     TESTFLAG = -L/usr/local/lib -pedantic  -Wall -Werror -Wextra -lgtest -lgtest_main -lsubunit -pthread -lstdc++ -lm
# else
#     TESTFLAG = -L/usr/local/lib -lgtest -lgtest_main -pthread -lstdc++ -lm
# endif

$(STATIC_LIB):
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar rcs $(STATIC_LIB)  *.o
	ranlib $(STATIC_LIB)
	rm -rf *.o

test: clean style
	$(CC) $(CFLAGS) $(TEST_FILE) $(LFLAGS) -g -o $(TEST_OUT)
	./$(TEST_OUT)


clean:
	rm -rf *.o coverage_info coverage_report *.a *.gcda *.gcno *.info *.gcov report $(GCOV_OUT) $(TEST_OUT) $(A_OUT) *.dSYM

style:
	@clang-format --style=Google -i  $(SOURCE) $(TEST_FILE)
	@echo "Don't panic! Clang is fine :)"


style_test:
	@clang-format --style=Google -n $(SOURCE) $(TEST_FILE)
	@echo "Don't panic! Clang is fine :)"

gcov_report: clean style test
	@( $(CC) $(CFLAGS) $(TEST_FILE) --coverage -o $(GCOV_OUT)  $(TESTFLAG))
	@( chmod +x ./$(GCOV_OUT) )
	@( ./$(GCOV_OUT) )
	@  mkdir -p coverage_info
	@( lcov --capture --directory . --rc lcov_branch_coverage=1 --output-file coverage_info/coverage.info )
	@( lcov --list coverage_info/coverage.info )
	@( genhtml coverage_info/coverage.info --output-directory --rc lcov_branch_coverage=1 coverage_report)
	@( open coverage_report/index.html )
