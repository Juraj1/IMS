CFLAGS= -std=c++11 -g -Wall -pedantic -Werror -c
CC=g++
OBJFILES=	chicken.o\
		factory.o\
		main.o
DEBUG=-DDEBUG

drubezarna:$(OBJFILES)
	$(CC) $(OBJFILES) -o drubezarna
factory.o:factory.cpp
	$(CC) $(CFLAGS) factory.cpp
chicken.o:chicken.cpp
	$(CC) $(CFLAGS) chicken.cpp
main.o:main.cpp
	$(CC) $(CFLAGS) main.cpp


clean:
	rm -rf *.o

debug_add_flag: CFLAGS += -DDEBUG
debug_add_flag:drubezarna

debug: debug_add_flag
