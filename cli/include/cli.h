#ifndef CLI_H
#define CLI_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
// # include <string.h>
// # include <stdio.h>
// # include <stdlib.h>

# define LOG_PATH "../logs/log.log"

typedef struct s_get
{
	int		slash;
	int		coins;
	int		btc;
}	t_get;

typedef struct s_data
{
	FILE	*file_log;
	int		show_code;
	char	buff[50];
	t_get	counter;
}	t_data;

int		check_args(t_data *data, int argc, char *argv[]);
void	count_methods(t_data *data);
void	show_cli(t_data *data);



#endif