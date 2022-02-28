#include "../include/api.h"

static int s_signo;

void signal_handler(int signo)
{
	s_signo = signo;
}

void get_route(struct mg_http_message *request, struct mg_connection *c)
{
		char *url;
		// void logging;
		if (mg_http_match_uri(request, "/")) 
		{
			mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"OK\": %s}", "\"BATATA\"");
			LOG_PRINT("%s", request->method.ptr);
		} 
		else if(mg_http_match_uri(request, "/coins"))
		{
			url = COINS;
			mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s", curlfn(url));	//FAZER OS LOGS
			LOG_PRINT("%s", request->method.ptr);
		}
		else if(mg_http_match_uri(request, "/btc"))
		{
			url = BTC;
			mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s", curlfn(url));	//FAZER OS LOGS
			LOG_PRINT("%s", request->method.ptr);
		}
		else{
			mg_http_reply(c, 400, NULL, "{\"ERRO\": %s}", "\"Invalid URI\"");
			LOG_PRINT("%s", request->method.ptr);
		}
}

 int	choose_method(const char *method)
{
	if (!strncmp(method, "GET", 3))
		return (GET);
	// else if (!strncmp(method, "POST", 4))
	// 	return (POST);
	// else if (!strncmp(method, "PUT", 3))
	// 	return (PUT);
	// else if (!strncmp(method, "DELETE", 6))
	// 	return (DELETE);
	// else if (!strncmp(method, "PATCH", 5))
	// 	return (PATCH);
	else
		return (METHODS);
}

 void fn_call_back(struct mg_connection *connect, int ev, void *ev_data, void *fn_data) 
{
	struct mg_http_message *request = (struct mg_http_message *)ev_data;

	if (ev == MG_EV_HTTP_MSG) 
	{
		int	method = choose_method(request->method.ptr);
		if (method == GET)
			get_route(request, connect);
		else
		{
			mg_http_reply(connect, 400, NULL, "JUST METHOD GET", method);
			LOG_PRINT("%s", request->method.ptr);
		}
		
	}
	(void)fn_data;
}

int server() 
{
	struct mg_mgr mgr;
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, URL, fn_call_back, &mgr);
		
	while (s_signo == 0)
		mg_mgr_poll(&mgr, 1000);
	mg_mgr_free(&mgr);
	return 0;
}