CC = gcc
SOURCE = template.cpp

OBJECTS = $(patsubst %.cpp,%.o, $(SOURCE))
CFLAGS = -std=c++17 -lstdc++

TEST_OUT = a.out


all: $(TEST_OUT)
	@ ./$(TEST_OUT)

$(TEST_OUT): $(OBJECTS)
	@$(CC) $^ $(CFLAGS)  -o $@
	@rm -rf *.o

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clang:
	@cp ../../materials/linters/.clang-format .clang-format
	@clang-format -i *.cpp *.c
	@rm -rf .clang-format
	@echo "Don't panic! Clang is fine :)"

	
clean:
	@( rm -rf *.o *.a $(TEST_OUT) coverage_info coverage_report *.dSYM gtest_test *.gcno *.gcda *.out )
	@echo "Old version deleted!"

valgrind: test
	@( valgrind --tool=memcheck --leak-check=yes ./test )
	@echo "Valgrind completed."