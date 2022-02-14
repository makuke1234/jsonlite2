#include <jsonlite2.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testJL2(const char * contents, size_t contLen, const char * what, size_t maxIter)
{
	json_t obj;
	clock_t start = clock();

	size_t errors = 0;
	for (size_t i = 0; i < maxIter; ++i)
	{
		jsonErr_t err = json_parse(&obj, contents, contLen);
		if (err != jsonErr_ok)
		{
			++errors;
			continue;
		}
		json_destroy(&obj);
	}

	clock_t stop = clock();
	printf("Time elapsed (%s):\t%g seconds; %zu errors\n", what, (double)(stop - start) / (double)CLOCKS_PER_SEC, errors);
}

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Filename not given!\n");
		return 1;
	}
	else if (argc < 3)
	{
		fprintf(stderr, "Iteration count not given\n");
		return 1;
	}

	size_t maxIter = (size_t)strtoul(argv[argc - 1], NULL, 10);
	for (int i = 1; i < (argc - 1); ++i)
	{
		printf("Testing file \"%s\":\n", argv[i]);

		FILE * inp = fopen(argv[i], "rb");
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

		printf("Contents length: %ld bytes\n", contLen);

		testJL2(contents, contLen, "jsonlite2", maxIter);

		free(contents);
	}

	return 0;
}
