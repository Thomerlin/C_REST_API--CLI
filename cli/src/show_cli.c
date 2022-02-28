#include "../include/cli.h"

static void	print_logs(t_data *data)
{
	printf("********************************************\n");
	printf("|   REQUESTS  | HTTP Method  |   Path      |\n");
	printf("|******************************************|\n");
	printf("|     %d      |     GET      |        /     |\n", \
		data->counter.slash);
	printf("|******************************************|\n");
	printf("|     %d      |     GET      |     /coins   |\n", \
		data->counter.coins);
	printf("|******************************************|\n");
	printf("|     %d      |     GET      |     /btc     |\n", \
		data->counter.btc);
	printf("|******************************************|\n");
}

static void	print_get_slash(t_data *data)
{
	printf("********************************************\n");
	printf("|   REQUESTS  | HTTP Method  |   Path      |\n");
	printf("|******************************************|\n");
	printf("|     %d      |     GET      |        /     |\n", \
		data->counter.btc);
	printf("|******************************************|\n");
}

static void	print_get_coins(t_data *data)
{
	printf("********************************************\n");
	printf("|   REQUESTS  | HTTP Method  |   Path      |\n");
	printf("|******************************************|\n");
	printf("|     %d      |     GET      |     /coins   |\n", \
		data->counter.btc);
	printf("|******************************************|\n");
}

static void	print_get_btc(t_data *data)
{
	printf("********************************************\n");
	printf("|   REQUESTS  | HTTP Method  |    Path     |\n");
	printf("|******************************************|\n");
	printf("|     %d      |     GET      |      /btc    |\n", \
		data->counter.btc);
	printf("|******************************************|\n");
}

void	show_cli(t_data *data)
{
	if (data->show_code == 0)
		printf("COMMAND INVALID\n");
	if (data->show_code == 1)
		print_logs(data);
	if (data->show_code == 2)
		print_get_slash(data);
	if (data->show_code == 3)
		print_get_coins(data);
	if (data->show_code == 4)
		print_get_btc(data);
}