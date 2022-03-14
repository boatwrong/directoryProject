# target: dependencies
#     compiler comp_flags file_output_flag file_output_name 
# $@ = target 
# $^ = dependencies
CC=gcc
CFLAGS=-Wall
OBJS=main.o filework.o

directory: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

filework.o: filework.c filework.h
	$(CC) $(CFLAGS) -c $^

main.o: main.c filework.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o directory filework.h.gch
