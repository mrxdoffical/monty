#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdarg.h>
#define _POSIX_C_SOURCE 200809L
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *header;
typedef void (*op_func)(stack_t **, unsigned int);
/*error functions*/
void error_1(int error_code, ...);
void error_2(int error_code, ...);
void str_errors(int error_code, ...);
/*stack functions*/
void insert_stack(stack_t **n_node, __attribute__((unused))unsigned int ln);
void pop_max(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void free_node(void);
stack_t *node_creator(int n);
void free_node(void);
void queue_adder(stack_t **new_node, __attribute__((unused))unsigned int ln);
/*math func*/
void nop(stack_t **stack, unsigned int line_number);
void node_swapper(stack_t **stack, unsigned int line_number);
void node_addittion(stack_t **stack, unsigned int line_number);
void node_substractor(stack_t **stack, unsigned int line_number);
void node_dividing(stack_t **stack, unsigned int line_number);
void node_mul(stack_t **, unsigned int);
void node_mod(stack_t **, unsigned int);
/*file functions*/
void file_opener(char *file_name);
void file_r(FILE *fd);
int line_praser(char *buffer, int line_number, int format);
int len_chars(FILE *);
void find_func(char *opcode, char *value, int length, int f);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotate_left(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotate_right(stack_t **stack, __attribute__((unused))unsigned int ln);

#endif
