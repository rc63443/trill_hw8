/*
 * =====================================================================================
 *
 *       Filename:  trill_hw8_task2.c
 *       	Usage:  ./trill_hw8_task2.c
 *    Description:  Reads input until EOF and echoes it formatted
 *
 *        Version:  1.0
 *        Created:  03/23/2017 04:19:43 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Julie Collings (), juliecollings@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXELS 81
/* Function Prototypes */
void Usage(char **info);
char GetOptions(char *parameter[]);
void PrintOption(char input, char original[MAXELS]);
/* Main Program */
int main(int argc, char *argv[])
{
	char string1[MAXELS] = "--help";
	char option = ' ';
	int n, i = 0;
	char c;
	char input[MAXELS];
	//If help is selected, call Usage
	n = strcmp(string1, argv[1]);
	if(n == 0)
	{
		Usage(argv);
		exit(1);
	}
	//If first input parameter is --help, call help
	//Check to see if 1 input parameter
	if (argc != 2)
	{
		printf("Missing or wrong number of parameters\n");
		Usage(argv);
		exit(1);
	}
	//Extract choice
	option = GetOptions(argv);
		printf("Type input.  Output will be based on option\nEnter Ctrl-D to stop user input: ");
		while(1)
		{	
			input[0] = '\0';
			i = 0;
			while(i < (MAXELS - 1) && (c = getchar()) != '\n')
			{
				if (c == EOF)
				{
					exit(0);
				}
				input[i] = c;
				i++;
			}
			input[i] = '\0';
			PrintOption(option, input);
		}
	return 0;
	
}

/* Function Definitions */
void Usage(char **info)
{
	//Takes a pointer to an array of pointers; how argv is defined
	printf("Usage: ./trill_hw8_task2 [-p | -u | -l]\n");
	return;
}
//Parse string to extract choice and return a char with that choice
char GetOptions(char *parameter[])
{
	int n;
	char choice;
	char string1[MAXELS] = "-p";
	char string2[MAXELS] = "-l";
	char string3[MAXELS] = "-u";
	n = strcmp(string1, parameter[1]);
	if (n == 0)
	{
		choice = 'p';
		printf("Selecting option %c\n", choice);
	}
	else if (n > 0)
	{
		n = strcmp(string2, parameter[1]);
		if(n == 0)
		{
			choice = 'l';
			printf("Selecting option %c\n", choice);
		}
		else
		{
			choice = 'p';
			printf("%s is an invalid flag; using default flag(-p)\n", parameter[1]);
		}
	}
	else
	{
		n = strcmp(string3, parameter[1]);
		if(n == 0)
		{
			choice = 'u';
			printf("Selecting option %c\n", choice);
		}
		else
		{
			choice = 'p';
			printf("%s is an invalid flag; using default flag(-p)\n", parameter[1]);
		}
	}
	return (choice);
}
//format and print string
  void PrintOption(char input, char original[])
{
	int i = 0;
	switch (input)
	{
		case 'p':
			break;
		case 'l':
			while(original[i] != '\0')
			{
				original[i] = tolower(original[i]);
				i++;
			}
			break;
		case 'u':
			while(original[i] != '\0')
			{
				original[i] = toupper(original[i]);
				i++;
			}
			break;
	}
	
	printf("%s\n", original);
	return;
}
