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

#define VAL 1024
#define args_count 150
#define buffe_size 1024
#define total_args 1024

/**
 * struct mem_record - struct
 * @buff_ptr: pointer
 * @next: next node
 */

typedef struct mem_record
{
	char *buff_ptr;
	struct mem_record *next;
} buff_list;

/**
 * struct shell_cmds - builtin functions
 * @command: command name
 * @pr: pointer to function
 */

typedef struct shell_cmds
{
	char *command;
	int (*pr)(char *const*);
} shell_cmd;

/*Main code prototype goes under here*/



/*Malloc program prototype go under here*/
char *mal_alloc(char *pointer, size_t val);
char *new_alloc(char *pointer, size_t buffsize_new);
void free_stat_buff(buff_list **head);
char *buff_set(char *k, char c, unsigned int b);
buff_list *add_buff(buff_list **head, char *pointer);
void buff_free(buff_list **head);
char **strn_tokn(char *tokn);
size_t tokn_ln(char *strn, size_t spec);
size_t tokn_cnt(char *strn);
void rec_sig(int sign);
void rec_sig(int sign __attribute__((unused)));
ssize_t buff_cp(char **app_str, char *res_str, ssize_t *start);
void shft_bf(char *buf, ssize_t q);
ssize_t get_line(char **mem);
size_t strn_len(const char *strng);
char **gen_path(char *const *arg);
size_t path_avail(char *const *arg);
size_t arg_len(char *ptr_path);
size_t num_path(char *ar_path);
size_t tokn_ln(char *strn, size_t spec);
size_t tokn_cnt(char *strn);
char **strn_tokn(char *tokn);
char **gen_path(char *const *arg);
size_t path_avail(char *const *arg);
size_t arg_len(char *ptr_path);
size_t num_path(char *ar_path);
char **strn_tokn(char *tokn);
void rec_sig(int sign);
void rec_sig(int sign __attribute__((unused)));
int main(int argc __attribute__((unused)), char **arg);
ssize_t buff_cp(char **app_str, char *res_str, ssize_t *start);
int buff_alloc(char *buf);
void shft_bf(char *buf, ssize_t q);
ssize_t get_line(char **mem);
size_t strn_len(const char *strng);
void argument(void);

/*external variables go here*/
extern char **environ;
extern buff_list *buff_head;
buff_list *buff_head;
extern buff_list *buff_stat_head;
buff_list *buff_stat_head;
extern size_t msg_err;
size_t msg_err;

/*execution prototypes go here*/
int process_builtin(char *const *arg);
int ext_command(char *const *arg);
int cd_dir(char *const *arg);
int oldPWD_set(void);
int PWD_set(char *var_v);
int _strcomp(const char *strn1, const char *strn2);
int strn_compl(const char *strn1, const char *strn2, size_t q);


int main(int argc __attribute__((unused)), char **arg);
int buff_alloc(char *buf);
int _strcomp(const char *strn1, const char *strn2);
int strn_compl(const char *strn1, const char *strn2, size_t q);


int exec_cmd(char *const *arg);

/*dir change.c prototypes*/
int cd_home(void);
int cd_current(void);
int cd_prnt(void);
int cd_user(char *arg);
char *var_get(char *environ_n);
int cd_wd(char *dir_path);
int cd_before(void);

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
char *str_reverse(char *str);
char *copy_strnl(char *s1, const char *s2, size_t t);
char *cat_strn(char *app_str, const char *res_str);




#endif
