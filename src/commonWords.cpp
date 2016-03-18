/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int comp_words(char **, char *, int);

char ** commonWords(char *str1, char *str2) {
	int count1 = 0, count2 = 0, count3 = 0, result_row = 0, result_column = 0, index = 0, return_value = 0;
	char ** result = NULL;
	if (str1 == '\0' || str2 == '\0')
		return NULL;
	result = (char**)malloc(SIZE*sizeof(char*));
	for (index = 0; index < SIZE; index++)
		result[index] = (char*)malloc(SIZE*sizeof(char));
	index = 0;
	while (str1[index] != '\0')
	{
		if (str1[index] != ' ')
		{
			count1++;
			result[result_row][result_column] = str1[index];
			result_column++;
			index++;
		}
		else if ((str1[index] == ' ' && str1[index + 1] != ' ') || str1[index + 1] == '\0')
		{
			count2++;
			result[result_row][result_column] = '\0';
			return_value = comp_words(result, str2, result_row);
			if (return_value == result_column)
			{
				count3++; result_row++;
				result_column = 0;
			}
			else
			{
				result_column = 0;
				result[result_row][result_column] = '\0';

			}
			index++;
		}
		else
		{
			index++;
		}
	}
	if (count1 > 0 && count2 > 0 && count3 > 0)
		return result;
	else
		return NULL;
}
int comp_words(char ** str1, char *  str2, int num){
	int temp = num, count = 0, col = 0, index = 0;
	while (str2[index] != '\0'&&str1[num][col] != '\0')
	{
		if (str2[index] != ' ')
		{
			if (str1[num][col] == str2[index])
			{
				count++; col++;
				if (str1[num][col] == '\0'&&str2[temp + 1] == ' ')
					break;
			}
			else
				count = 0;
		}
		index++;
	}
	return count;
}