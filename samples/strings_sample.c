#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return line;
}

int main ()
{

	char *line;
	int bufsize = 64, position = 0;
	char **tokens = malloc(64 * sizeof(char*));
	char **copy_tokens;
	char *token;

	line = read_line();
	token = strtok(line, " ");
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				fprintf(stderr, "lsh: allocation error\n");
				exit(100);
			}
		}

		token = strtok(NULL, " ");
	}
	copy_tokens = tokens;
	while (copy_tokens != NULL)
	{
		copy_tokens++;
	}

}
