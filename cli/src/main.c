#include "../include/cli.h"

int	clifn(t_data *data, int argc, char *argv[])
{
	data->counter.slash = 0;
	data->counter.coins = 0;
	data->counter.btc = 0;
	if (check_args(data, argc, argv))
	{
		data->file_log = fopen(LOG_PATH, "r");
		if (!data->file_log)
		{
			perror("ERROR");
			exit(1);
		}
		count_methods(data);
		fclose(data->file_log);
	}
	show_cli(data);
	return 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (clifn(&data, argc, argv) == 1)
		return 1;
	return 0;
}