#ifndef API_H
#define API_H

# include <string.h>
# include <stdlib.h> 
# include <stdio.h>
# include <signal.h>
# include <stdarg.h>
# include <assert.h>
# include <time.h>

# include <json-c/json.h>
# include <curl/curl.h>
// # include <mysql/mysql.h>

# include "../libs/mongoose.h"

# define URL "localhost:8000"
# define COINS "https://api.blockchain.info/ticker"
# define BTC "https://api.coincap.io/v2/assets/bitcoin"

typedef struct s_ctx 
{
	json_object		*obj;
	json_tokener	*tok;
}				t_ctx;

enum e_methods
{
	GET,
	POST,
	PUT,
	DELETE,
	PATCH,
	METHODS
};

//MONGOOSE
void			get_route(struct mg_http_message *request, struct mg_connection *c);
int				choose_method(const char *method);
void			fn_call_back(struct mg_connection *c, int ev, void *ev_data, void *fn_data);
int				server();

void			signal_handler(int signo);

//CURL
const char		*curlfn(char *url);
size_t			writecb(void *buffer, size_t size, size_t nmemb, void *opq);

//logger
void			log_print(char *fmt,...);
#define LOG_PRINT(...) log_print( __VA_ARGS__ )

#endif