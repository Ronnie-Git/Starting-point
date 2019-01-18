CC := gcc
CFLAGS := -Wall -g -pthread
SHDIR := ../common
OBJS = master.c

pihealthd: $(OBJS)
	@$(CC) -o $@ $(CFLAGS) $(OBJS)

#$(OBJS) : %.o: %.c
#	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@rm -f *.o pihealthd
	@echo Done cleaning
