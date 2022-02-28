#include "../include/cli.h"

int	check_args(t_data *data, int argc, char *argv[])
{
	if (argc == 2)
	{
		if(strstr(argv[1], "logs"))
		{
			data->show_code = 1;
			return 1;
		}
		else if (!strcmp(argv[1], "/"))
		{
			data->show_code = 2;
			return 1;
		}
		else if (!strcmp(argv[1], "/coins"))
		{
			data->show_code = 3;
			return 1;
		}
		else if (!strcmp(argv[1], "/btc"))
		{
			data->show_code = 4;
			return 1;
		}
		else 
			data->show_code = 0;
		return 0;
	}
}