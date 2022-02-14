#include <jsonlite2.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Filename not given!\n");
		return 1;
	}

	FILE * inp = fopen(argv[1], "rb");
	if (inp == NULL)
	{
		fprintf(stderr, "File error!\n");
		return 1;
	}

	// Load contents
	fseek(inp, 0, SEEK_END);
	long contLen = ftell(inp);
	fseek(inp, 0, SEEK_SET);

	char * contents = malloc(contLen);
	if (contents == NULL)
	{
		fprintf(stderr, "Memory error!\n");
		return 1;
	}

	fread(contents, contLen, 1, inp);
	fclose(inp);

	json_t obj;
	jsonErr_t err = json_parse(&obj, contents, contLen);
	free(contents);
	contents = NULL;
	if (err != jsonErr_ok)
	{
		fprintf(stderr, "[JSON error]: %s\n", g_jsonErrors[err]);
		return 1;
	}

	err = json_dump(&obj, &contents, NULL);
	json_destroy(&obj);

	if (err != jsonErr_ok)
	{
		fprintf(stderr, "[JSON error]: %s\n", g_jsonErrors[err]);
		return 1;
	}
	fputs(contents, stdout);
	free(contents);

	return 0;
}
