#Makefile with Suffix Rules
CC = gcc
CFLAGS = -g -lrt -lpthread
TARGET1 = p0
OBJS1 = p0.o node.h
OBJS2 = tree.o tree.h node.h
LIBOBJS =
LIBS =
MYLIBS =

.SUFFIXES: .c .o

all: $(TARGET1)
p0: $(OBJS1) $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS1) $(OBJS2) -o $@
.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.log *.o *~ $(TARGET1)
