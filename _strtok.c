
char **_strtok(char *line)
{
  char *arg;
  char **args:

    arg = strtok(line, /* Delimiter*/)
    while (arg != NULL)
      {
	args[pos] = arg;
	pos++;
	arg = strtok(NULL, /*Delimiter*/)
      }
  args[pos] = NULL;
  return (args);
}
