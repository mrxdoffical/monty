#include "monty.h"

/**
 * open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void file_opener(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		error_1(2, file_name);

	file_r(fd);
	fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void file_r(FILE *fd)
{
	int line_number, f = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		f = line_praser(buffer, line_number, f);
	}
	free(buffer);
}

/**
 * line_praser - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @f:  storage f. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int line_praser(char *buffer, int line_number, int f)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error_1(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (f);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, f);
	return (f);
}


/**
 * fun_caller - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @operaton: string representing the opcode.
 * @value: string representing a numeric value.
 * @length: line numeber for the instruction.
 * @f: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void fun_caller(op_func func, char *operaton, char *value, int length, int f)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(operaton, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			error_2(5, length);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error_2(5, length);
		}
		node = node_creator(atoi(value) * flag);
		if (f == 0)
			func(&node, length);
		if (f == 1)
			queue_adder(&node, length);
	}
	else
		func(&header, length);
}
/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @f:  storage f. If 0 Nodes will be entered as a stack.
 * @length: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int length, int f)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", insert_stack},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop_max},
		{"nop", nop},
		{"swap", node_swapper},
		{"add", node_addittion},
		{"sub", node_substractor},
		{"div", node_dividing},
		{"mul", node_mul},
		{"mod", node_mod},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			fun_caller(func_list[i].f, opcode, value, length, f);
			flag = 0;
		}
	}
	if (flag == 1)
		error_2(3, length, opcode);
}