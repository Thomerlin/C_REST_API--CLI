#include "../include/api.h"

int main(void) 
{
	char *url = COINS;
	
	signal(SIGINT, signal_handler);
	curlfn(url);
	server();
	// signal(SIGTERM, signal_handler);
	
	return 0;
}