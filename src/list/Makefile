CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra

SOURCE = list.tpp
OBJECTS = $(subst .tpp,.o, $(SOURCE))


list.a: $(OBJECTS)
	ar rcs list.a $^
	ranlib list.a
	rm -rf *.o

%.o: %.tpp
	$(CC) $(CFLAGS) -c $< -o $@

testim: clean
	$(CC)  main.cpp -o testim
	./testim

testim_list:
	rm -rf tst
	$(CC) main_org.cpp -o tst
	./tst

clean:
	rm -rf testim

style_correct:
	cp ../../materials/linters/.clang-format .
	clang-format -i *.cpp
