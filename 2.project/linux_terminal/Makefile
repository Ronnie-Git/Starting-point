CC=gcc
OBJ=main.o info.o common.c

a.out: $(OBJ)
	$(CC) $(OBJ)

main.o: main.c
	$(CC) -c main.c

info.o: info.c
	$(CC) -c info.c

common.o: common.c
	$(CC) -c common.c

.PHONY: clean

clean:
	rm *.o a.out
