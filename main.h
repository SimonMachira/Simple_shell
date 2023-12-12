#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>

#define
#define
#define
#define

/**
 * struct mem_record - struct
 * @buff_ptr: pointer
 * @next: next node
 */

typedef struct mem_record
{
	char *buff_ptr;
	struct mem_record *next;
}buff_list;

/**
 * struct shell_cmd - builtin functions
 * @command: command name
 * @pr: pointer to function
 */

typedef struct shell_cmds
{
	char *command;
	int (*pr)(char *const*);
}shell_cmd;

/*Main code prototype goes under here*/

/*Malloc program prototype go under here*/
char *mal_alloc(char *pointer, size_t val);
char *new_alloc(char *pointer, size_t buffsize_new);
void free_stat_buff(buff_list **head);
char *buff_set(char *k, char c, unsigned int b);
buff_list *add_buff(buff_list **head, char *pointer);
void buff_free(buff_list **head);

/*external variables go here*/

/*execution prototypes go here*/
int process_builtin(char *const *arg);
int ext_command(char *const *arg);
int cd_dir(char *const *arg);
int exec_cmd(char *const *arg);

/*dir change.c prototypes*/
int cd_home(void);
int cd_current(void);
int cd_prnt(void);
int cd_user(char *arg);
char *environ_var(char *environ_n);
int cd_wd(char *dir_path);
int cd_before(void);

/*to check*/
void argument()

/*set pwd functions*/

/*atoi prototype*/
char *_atoi(size_t num, char *buff, int tok);
size_t digit_count(size_t digit);

/*major functions prototypes*/
int _stoi(char *str);
void err_print(size_t rpt, char *arg, char **token);
char *gen_err(char *ptr2, char **token);
int terminate(char *const *arg);
int isDigit(char str);



char *_atoi(size_t num, char *buff, int tok);
size_t digit_count(size_t digit);
int _stoi(char *str);

#endif
