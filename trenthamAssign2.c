/* YOUR NAME HERE
 * CSCI 4100
 * Programming Assignment 2
 * The Nut Shell - a simple shell that executes commands 
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE 256
#define MAX_ARGS 64

int is_blank(const char *cmd);
void parse_args(const char *cmd, char *argv[]);
void read_line(char *line);

int main()
{
  char* line [MAX_LINE];
  char* args [MAX_ARGS];
  read_line(line);

  printf(&line);
  /*while(line != "exit")
  {
    if(is_blank(*line) = 1)
    {
      read_line(*line);
    }
    else if(line == "exit")
    {
      exit(0);
    }
    else
    {
      parse_args(*line, *args);
    }
    
  }*/


}

/* Checks if a string contains only whitespace
 * str - the string to check
 * returns 1 if str contains whitespace, 0 otherwise
 */
int is_blank(const char *str)
{
  int i = 0;
  while(str[i] != '\0') {
    if(!isspace(str[i++]))
      return 0;
  }
  return 1;
}

/* Reads a line of text from the console
 * line - an allocated array of characters of size MAX_LINE
 * where the function can store all of the characters read.
 */
void read_line(char *line)
{
  char c;
  int chars_read = 0;
  while((c = getchar()) != '\n' && chars_read < MAX_LINE)
    line[chars_read++] = c;
  line[chars_read] = '\0';
}

/* Breaks a command line into individual strings containing the
 * command and all of its arguments
 * cmd - a string containing the command line
 * argv - an allocated array of strings of size MAX_ARGS where the
 * command and its arguments will be stored.
 */
void parse_args(const char *cmd, char *argv[])
{ 
  int argc = 0;
  while(*cmd != '\0' && argc < MAX_ARGS) {
    int i = 0;
    while(!isspace(cmd[i]) && cmd[i] != '\0') i++;
    argv[argc] = (char *) malloc(i + 1);
    strncpy(argv[argc], cmd, i);
    while(isspace(cmd[i])) i++;
    cmd += i;
    argc++;
  }
  if(argc < MAX_ARGS)
    argv[argc] = NULL;
  else
    argv[MAX_ARGS - 1] = NULL;
}
