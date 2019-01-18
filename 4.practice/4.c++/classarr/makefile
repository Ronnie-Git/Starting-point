CXX := g++
CFLAGS := -Wall -g
OBJS = main.o arr.o

a.out: $(OBJS)
	@$(CXX) -o $@ $(CFLAGS) $(OBJS)

$(OBJS) : %.o: %.cpp
	@$(CXX) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@rm -f *.o a.out
	@echo Done cleaning
