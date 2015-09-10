CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o read_instr.o write_log.o draw.o linked_list.o effects.o
turtle:			$(OBJ)
				$(CC) $(CFLAGS) -o turtle $(OBJ) -lm

main.o: 		main.c read_instr.h linked_list.h draw.h 
				$(CC) $(CFLAGS) -c main.c

read_instr.o:	read_instr.c read_instr.h linked_list.h
				$(CC) $(CFLAGS) -c read_instr.c

draw.o:			draw.c draw.h write_log.h linked_list.h effects.h
				$(CC) $(CFLAGS) -c draw.c

write_log.o:	write_log.c write_log.h
				$(CC) $(CFLAGS) -c write_log.c

linked_list.o:	linked_list.c linked_list.h
				$(CC) $(CFLAGS) -c linked_list.c

effects.o:		effects.c effects.h
				$(CC) $(CFLAGS) -c effects.c
clean:
			rm $(OBJ) turtle
