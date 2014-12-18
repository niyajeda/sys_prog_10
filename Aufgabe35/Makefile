CC=gcc
CFLAGS="-Wall"

DEPS =
OBJ = tree.o

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) 
tree: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
debug:$(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
clean:
	rm -vfr *~ tree *.o
	