CC := gcc
CFLAGS := -Wall -g
OBJS = main.o head.o

a.out: $(OBJS)
	@$(CXX) -o $@ $(CFLAGS) $(OBJS)

$(OBJS) : %.o: %.c
	@$(CXX) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@rm -f *.o a.out
	@echo Done cleaning
