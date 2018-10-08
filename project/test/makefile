CC = gcc
CFLAGS = -I./thirdpart/include -DTEST_FUNC -std=c11 -Wall -g
OBJS = main.o is_prime.o add.o sqrt1.o newton.o quick_pow.o

.PHONY: clean

a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) thirdpart/libs/libtest.a -lm
    
main.o : main.c
	$(CC) -c $(CFLAGS) main.c

is_prime.o : is_prime.c is_prime.h
	$(CC) -c $(CFLAGS) is_prime.c

add.o : add.c add.h
	$(CC) -c $(CFLAGS) add.c

sqrt1.o : sqrt1.c sqrt1.h
	$(CC) -c $(CFLAGS) sqrt1.c

newton.o : newton.c newton.h
	$(CC) -c $(CFLAGS) newton.c

quick_pow.o : quick_pow.c quick_pow.h
	$(CC) -c $(CFLAGS) quick_pow.c

clean:
	rm -rf *.o a.out
