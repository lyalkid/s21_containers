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
	$(CC) $(CFLAGS) main.cpp -o testim
	./testim

testim_mylist: clean
	$(CC) main.cpp list.tpp -o tst
	./tst

clean:
	rm -rf testim

style_correct:
