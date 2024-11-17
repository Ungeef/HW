all: temp

temp: main_temp.o function_temp.o
	gcc -o temp main_temp.o function_temp.o
	temp -f temperature_small.csv

main_temp.o: main_temp.c temp_lib.h
	gcc -c -o main_temp.o main_temp.c

function_temp.o: function_temp.c
	gcc -c -o function_temp.o function_temp.c

clean:
	del *.o
	del temp.exe