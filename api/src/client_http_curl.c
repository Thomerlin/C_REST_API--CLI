#include "../include/api.h"

size_t write_cb(char *buffer, size_t size, size_t nmemb, void *opq)
{
	size_t len = size * nmemb;

	t_ctx *ctx = (t_ctx *) opq;
	ctx->obj = json_tokener_parse_ex(ctx->tok, buffer, len);
	switch (json_tokener_get_error(ctx->tok))
	{
		case json_tokener_continue:
		case json_tokener_success:
			return len;
		default:
			return 0;
	}
}

const char	*curlfn(char *url)
{
	enum json_tokener_error jerr;
	t_ctx ctx = { NULL, json_tokener_new() };
	CURL *curl;
	CURLcode res;

	const char *response;

	assert(ctx.tok);

	// curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &ctx);
    
	res = curl_easy_perform(curl);
	response = json_object_to_json_string(ctx.obj);

	if (res != CURLE_OK)
	{
		fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
		goto done;
	}

	if ((jerr = json_tokener_get_error(ctx.tok)) != json_tokener_success)
	{
		fprintf(stderr, "json error: %s\n", json_tokener_error_desc(jerr));
		goto done;
	}
	//   printf("%s\n", json_object_to_json_string(ctx.obj));
	done:
		curl_easy_cleanup(curl);
		curl_global_cleanup();

		if (ctx.tok)
			json_tokener_free(ctx.tok);

		if (ctx.obj)
			json_object_put(ctx.obj);

	return response;
}