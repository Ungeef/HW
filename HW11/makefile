all: prog

prog: function_temp.o
	gcc -o prog function_temp.o

function_temp.o: function_temp.c
	gcc -c -o function_temp.o function_temp.c

clean:
	del *.o
	del prog.exe