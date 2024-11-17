#include "temp_lib.h"

int ERROR[12] = {0};

void remove_index(dyn_sensor *st, int indx)
{
	if (indx < 0 || indx >= st->sp)
	{
		fprintf(stderr, "Invalid index\n");
		return;
	}

	for (int i = indx; i < st->sp - 1; ++i)
	{
		st->data[i] = st->data[i + 1];
	}

	st->sp--;
}

void SwapSensors(sensor *info, int i, int j)
{
	sensor temp = info[i];
	info[i] = info[j];
	info[j] = temp;
}

void SortByT(sensor *info, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (info[i].t > info[j].t)
			{
				SwapSensors(info, i, j);
			}
		}
	}
}

unsigned int DateToInt(sensor *info)
{
	return (info->year << 16) | (info->month << 8) | info->day;
}

void SortByDate(sensor *info, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (DateToInt(&info[i]) > DateToInt(&info[j]))
			{
				SwapSensors(info, i, j);
			}
		}
	}
}

void init_stack(dyn_sensor *st)
{
	st->size = 1;
	st->sp = 0;
	st->data = malloc(st->size * sizeof(sensor));
}

void delete_stack(dyn_sensor *st)
{
	free(st->data);
}

void push(dyn_sensor *st, sensor data)
{
	if (st->sp >= st->size - 12)
	{
		st->size *= 2;
		st->data = realloc(st->data, st->size * sizeof(sensor));
	}
	st->data[st->sp++] = data;
}

void print_all(dyn_sensor st, int count)
{
	static int num = 0;
	printf("#  Year  Month  Day  Hour  Minute  Temp\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-2d %-8d%-6d%-5d%-7d%-7d%d\n", num, st.data[i].year, st.data[i].month, st.data[i].day, st.data[i].hour, st.data[i].minute, st.data[i].t);
		num++;
	}
}

int Readfile(dyn_sensor *st, char *input_fn)
{
	// char *input_fn = "temperature_small.csv";
	char line[256];
	FILE *fp;
	sensor temp;
	int real_count = 0, done_count = 0;
	if ((fp = fopen(input_fn, "r")) == NULL)
	{
		perror("Error occured while opening input file!");
		return -1;
	}

	while (fgets(line, sizeof(line), fp))
	{
		real_count++;
		if (sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &temp.year, &temp.month, &temp.day, &temp.hour, &temp.minute, &temp.t) == 6)
		{
			push(st, temp);
			done_count++;
		}
		else
		{
			if (temp.month > 0 && temp.month < 13)
				ERROR[temp.month - 1]++;
			printf("Error in line %d\n", real_count);
		}
	}

	fclose(fp);
	return done_count;
}

float Month_statistic(dyn_sensor st, int count, int month_usr_take)
{
	float avg = 0;
	int min = 5500, max = -273;
	int count_month = 0;
	static int dig = 1;
	float avg_year = -273;
	for (int i = 0; i < count; i++)
	{
		if (month_usr_take == st.data[i].month)
		{
			if (st.data[i].t > max)
				max = st.data[i].t;
			if (st.data[i].t < min)
				min = st.data[i].t;
			avg += st.data[i].t;
			count_month++;
			// printf("%d %d %d %d %d %d\n", st.data[i].year, st.data[i].month, st.data[i].day, st.data[i].hour, st.data[i].minute, st.data[i].t);
		}
	}
	if (count_month != 0)
	{
		avg /= count_month;
		avg_year = avg;
		printf("%-2d %-8d%-7d%-5d%-10.2f%-10d%-8d\n", dig, st.data[0].year, month_usr_take, ERROR[month_usr_take - 1], avg, min, max);
		dig++;
	}
	else
	{
		printf("No records for %d month\n", month_usr_take);
		dig++;
	}
	return avg_year;
}

void Year_statistic(dyn_sensor st, int count, float avg)
{
	int min = 5500, max = -273;
	for (int i = 0; i < count; i++)
	{
		if (st.data[i].t > max)
			max = st.data[i].t;
		if (st.data[i].t < min)
			min = st.data[i].t;
		// printf("%d %d %d %d %d %d\n", st.data[i].year, st.data[i].month, st.data[i].day, st.data[i].hour, st.data[i].minute, st.data[i].t);
	}
	int SumErr = 0;
	for (int i = 0; i < 12; i++)
	{
		SumErr += ERROR[i];
	}
	if (count != 0)
	{
		printf("1 %-8d%-6d%-10.2f%-9d%-8d", st.data[0].year, SumErr, avg, min, max);
	}
	else
	{
		printf("No records for this year");
	}
}
