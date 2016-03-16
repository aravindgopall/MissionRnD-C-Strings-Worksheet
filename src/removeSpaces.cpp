/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) 
{

     if (str!='\0')
	{
		int len=0;
		while (str[len] != '\0')
		{
			if (str[len] == ' '){
				int l = 0;
				for ( l = len; str[l] != '\0'; l++)
					str[l] = str[l + 1];
				len--;
			}
			len++;
		}
		return str[0];
	}
	else
		return '\0';
}