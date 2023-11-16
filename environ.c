#include "shell.h"

/**
 * _myenv - prints the current env
 * @info: Str containing potential arguments used to maintain
 constant function prototype.
 * Return: Always 0(Success).
 *
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environment variable.
 * @info: Str containing potential arguments,used for maintaining the constant function prototype.
 * @name: Environment variable name.
 *
 * Return: The value.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initializes a new env var
 or modify the existing one.
 * @info: Str containing potential arg used for maintaining
 the constant function prototype.
 *  Return: Always 0(Success).
 *
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - remove an env var.
 * @info: Str containing potential args used for maintaining
 the constant function prototype.
 * Return: Always 0(Success).
 *
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates environment linked-list.
 * @info: Str containing potential arguments used for maintaining the constant function prototype.
 * Return: Always 0(Success).
 *
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
