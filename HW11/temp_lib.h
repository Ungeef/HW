#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t t;
} sensor;

void cgangeIJ(sensor *info, int i, int j);
void SortByT(sensor *info, int n);
unsigned int DateToInt(sensor *info);
void SortByDate(sensor *info, int n);
void AddRecord(sensor *info, int number, uint16_t year, uint8_t month, uint8_t day, int8_t t);
int AddInfo(sensor *info);
void print(sensor *info, int number);

float Month_statistic(sensor st, int count, int month_usr_take);
void Year_statistic(sensor st, int count, float avg);