/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){

	int j = 0;
	strrev(input);
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i + 1] == ' ' || input[i+1] =='\0')
		{
			if (i + 1 != j){
				for (int l = i; l > j; l--, j++)
				{
					char temp = input[l];
					input[l] = input[j];
					input[j] = temp;
				}
			}

			j = i + 2;
		}
	}
}
