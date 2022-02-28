#include "../include/cli.h"

void	count_methods(t_data *data)
{
	bzero(data->buff, 50);
	while (fgets(data->buff, 50, data->file_log))
	{
		if (strstr(data->buff, "GET / "))
			data->counter.slash++;
		if (strstr(data->buff, "GET /coins"))
			data->counter.coins++;
		if (strstr(data->buff, "GET /btc"))
			data->counter.btc++;
	}
}