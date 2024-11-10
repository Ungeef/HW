all: prog

prog: temp_api.o
	gcc -o prog temp_api.o

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	del *.o
	del prog.exe