/*
 * =====================================================================================
 *
 *       Filename:  trill_hw8_task1.c
 *       	Usage:  ./trill_hw8_task1.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2017 04:13:06 PM
 *       Compiler:  gcc -Wall -Werr
 *         Author:  Robert Christensen (), robertchristensen1@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
/* Function Prototypes */
#define LEN 30
char *StringIn(char *myString, char *secondString);
void Usage(char **info);

/* Main Program */
int main(int argc, char *argv[])
{
	//char one[LEN], two[LEN];
	char *star = 0;
	
	do
	{
		if(argc !=3)
		{
			Usage(argv);
			exit(1);

		}

		star = StringIn(argv[1], argv[2]);

		if(star != NULL)
			printf("%s is in %s.\nReturned %s\n", argv[2], argv[1], star);
		
		else
				printf("Not found in string.\n");
			break;
		}
	while(1);
		{
			printf("Done\n");
		}
	return 0;
}

char *StringIn(char *myString, char *secondString)
{
	char* i = (char *) myString;
	int ii = strlen(secondString);

	while((i = strchr(i, *secondString)) != 0)
	{
		if (strncmp(i, secondString, ii) == 0)
			return i;
		i++;
	}
	return NULL;
}


void Usage(char **info)
{
	printf("Missing required parameters\n");
	printf("Usage ./trill_hw8_task1 <str1> <str2>\nProgram checks if str2 is part of str1\n");

}

