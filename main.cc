#include <iostream>
#include <string.h>
#include "Utilities/duktape/duktape.h"

/* For brevity assumes a maximum file length of 16kB. */
static void push_file_as_string(duk_context *ctx, const char *filename)
{
	FILE *f;
	size_t len;
	char buf[16384];

	f = fopen(filename, "rb");
	if (f)
	{
		len = fread((void *)buf, 1, sizeof(buf), f);
		fclose(f);
		duk_push_lstring(ctx, (const char *)buf, (duk_size_t)len);
	}
	else
	{
		duk_push_undefined(ctx);
	}
}


static duk_ret_t native_print(duk_context *ctx) {
	duk_push_string(ctx, " ");
	duk_insert(ctx, 0);
	duk_join(ctx, duk_get_top(ctx) - 1);
	printf("%s\n", duk_safe_to_string(ctx, -1));
	return 0;
}

int main(int argc, char *argv[])
{
	printf("Hello, world.\n");
	printf("\n(Press Return)\n");
	getchar();

	duk_context *ctx = NULL;
	char line[4096];
	std::string lin = "I like *Sam and Max*.";
	size_t idx;
	int ch;

	(void)argc;
	(void)argv;

	ctx = duk_create_heap_default();
	duk_push_c_function(ctx, native_print, DUK_VARARGS);
	duk_put_global_string(ctx, "print");
	
	if (!ctx)
	{
		printf("Failed to create a Duktape heap.\n");
		printf("\n(Press Return)\n");
		getchar();
		exit(1);
	}

	push_file_as_string(ctx, "process.js");
	if (duk_peval(ctx) != 0)
	{
		printf("Error: %s\n", duk_safe_to_string(ctx, -1));
		goto finished;
	}
	duk_pop(ctx); /* ignore result */

	duk_push_global_object(ctx);
	duk_get_prop_string(ctx, -1 /*index*/, "processLine");
	duk_push_string(ctx, &lin[0]);
	if (duk_pcall(ctx, 1 /*nargs*/) != 0)
	{
		printf("Error: %s\n", duk_safe_to_string(ctx, -1));
		getchar();
	}
	else
	{
		printf("%s\n", duk_safe_to_string(ctx, -1));
		getchar();
	}
	duk_pop(ctx); /* pop result/error */

finished:
	duk_destroy_heap(ctx);
	printf("\n(Press Return)\n");
	getchar();
	exit(0);
}