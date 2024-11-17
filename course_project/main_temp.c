#include "temp_lib.h"

int main(int argc, char *argv[])
{
	char input_fn[256] = "temperature_small.csv";
	sensor temp;
	dyn_sensor st;
	init_stack(&st);
	int num;
	_Bool is_read = 0;

	for (int i = 0; i < argc; i++)
	{
		char *str = argv[i];
		if (str[0] == '-')
		{
			switch (str[1])
			{
			case 'h':
				printf("-h for help\n");
				printf("-f file_name for load file\n");
				printf("-m xx statistic for xx month\n");
				printf("-p for print all document\n");
				printf("-a for adding record\n");
				printf("-r for remove record\n");
				break;
			case 'f':
				if (i + 1 >= argc)
				{
					fprintf(stderr, "No input file provided after -f flag.\n");
					return 1;
				}
				sscanf(argv[i + 1], "%s", input_fn);
				if (i + 2 == argc)
				{
					if (is_read == 0)
					{
						num = Readfile(&st, input_fn);
						is_read = 1;
					}

					if (num != -1)
					{
						printf("#  Year  Month  Error  TempAvg  TempMin  TempMax\n");
						float avg_year = 0, temp_avg;
						int count_month = 0;
						for (int j = 1; j < 13; j++)
						{
							temp_avg = Month_statistic(st, num, j);
							if (temp_avg != -273)
							{
								count_month++;
								avg_year += temp_avg;
							}
						}
						avg_year /= count_month;
						printf("# Year  Error  TempAvg  TempMin  TempMax\n");
						Year_statistic(st, num, avg_year);
					}
				}
				break;
			case 'm':
				if (i + 1 >= argc)
				{
					fprintf(stderr, "No # month provided after -f flag.\n");
					return 1;
				}
				if (is_read == 0)
				{
					num = Readfile(&st, input_fn);
					is_read = 1;
				}
				int temp = 0;
				sscanf(argv[i + 1], "%d", &temp);
				printf("# Year  Month  Error  TempAvg  TempMin  TempMax\n");
				Month_statistic(st, num, temp);
				break;
			case 'p':
				if (is_read == 0)
				{
					num = Readfile(&st, input_fn);
					is_read = 1;
				}
				if (i + 1 >= argc)
				{
					print_all(st, num);
				}
				else
				{
					if (strcmp(argv[i + 1], "t") == 0)
					{
						SortByT(st.data, num);
						print_all(st, num);
					}
					else if (strcmp(argv[i + 1], "d") == 0)
					{
						SortByDate(st.data, num);
						print_all(st, num);
					}
					else
					{
						fprintf(stderr, "Wrong parametr after -p\n");
					}
					i++;
				}
				break;

			case 'a':
				if (i + 6 >= argc)
				{
					fprintf(stderr, "Not enough arguments for adding a record.\n");
					return 1;
				}
				if (is_read == 0)
				{
					num = Readfile(&st, input_fn);
					is_read = 1;
				}
				sensor tmp;
				sscanf(argv[i + 1], "%hu", &tmp.year);
				sscanf(argv[i + 2], "%hhu", &tmp.month);
				sscanf(argv[i + 3], "%hhu", &tmp.day);
				sscanf(argv[i + 4], "%hhu", &tmp.hour);
				sscanf(argv[i + 5], "%hhu", &tmp.minute);
				sscanf(argv[i + 6], "%hhd", &tmp.t);
				push(&st, tmp);
				num++;
				i += 6;
				is_read = 1;
				break;
			case 'r':
				if (i + 1 >= argc)
				{
					fprintf(stderr, "No index for remove.\n");
					return 1;
				}
				if (is_read == 0)
				{
					num = Readfile(&st, input_fn);
					is_read = 1;
				}
				int remove_ind;
				sscanf(argv[i + 1], "%d", &remove_ind);
				remove_index(&st, remove_ind);
				num--;
				i++;
				break;

			default:
				printf("Wrong argument\n");
				break;
			}
		}
		if (argc == 1)
		{
			printf("-h for help\n");
			printf("-f file_name for load file\n");
			printf("-m xx statistic for xx month\n");
			printf("-p for print all document\n");
			printf("-a for adding record\n");
			printf("-r for remove record\n");
		}
	}

	delete_stack(&st);
	return 0;
}