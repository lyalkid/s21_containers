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

testim:
	$(CC) $(CFLAGS) main.cpp - o testim
	./testim

clean:
	rm -rf testim

style_correct:
