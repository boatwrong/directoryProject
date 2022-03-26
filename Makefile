# target: dependencies
#     compiler comp_flags file_output_flag file_output_name 
# $@ = target 
# $^ = dependencies
CC=gcc
CFLAGS=-Wall 
EXTRA_FLAG=-O3 -std=c11 -pedantic-errors -Wextra 
OBJS=main.o filework.o

directory: $(OBJS)
	$(CC) $(CFLAGS) -o main $^

filework.o: filework.c filework.h
	$(CC) $(CFLAGS) -c $^

main.o: main.c filework.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o main filework.h.gch
