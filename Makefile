CC       := gcc
CFLAGS   := -g -Wall -I.
LDFLAGS  := -lm -L.
LIBS     := -lpatricia

.PHONY: all test clean

all: libpatricia.a libpatricia.so ptest

patricia.o: patricia.c
	$(CC) $(CFLAGS) -fpic -c $^

libpatricia.a: patricia.o
	ar -r $@ $^
	ranlib $@

libpatricia.so: patricia.o
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDFLAGS)

test: ptest
	./ptest data/large.udp

ptest: ptest.c | libpatricia.a
	$(CC) $(CFLAGS) -o $@ $^ -lpatricia $(LDFLAGS) $(LIBS)

clean:
	$(RM) *.o *.d *.so *.a
	$(RM) -r *.dSYM
	$(RM) ptest

