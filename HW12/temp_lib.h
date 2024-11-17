#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	int8_t t;
} sensor;

typedef struct
{
	sensor *data;
	int size;
	int sp;
} dyn_sensor;

void remove_index(dyn_sensor *st, int indx);
void SwapSensors(sensor *info, int i, int j);
void SortByT(sensor *info, int n);
unsigned int DateToInt(sensor *info);
void SortByDate(sensor *info, int n);
void init_stack(dyn_sensor *st);
void delete_stack(dyn_sensor *st);
void push(dyn_sensor *st, sensor data);
void print_all(dyn_sensor st, int count);
int Readfile(dyn_sensor *st, char *input_fn);
float Month_statistic(dyn_sensor st, int count, int month_usr_take);
void Year_statistic(dyn_sensor st, int count, float avg);
