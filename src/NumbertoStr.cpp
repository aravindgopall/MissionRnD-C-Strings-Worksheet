/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<string.h>


void number_to_str(float number, char *str, int afterdecimal){
	
	int temp = afterdecimal,i=0,j=0;
	
		while (temp > 0)
		{
			number = number * 10;
			temp--;
			j = 1;//variable used to check the floating number
		}
		int result = (int)number;
		
		int result_temp = result;
		if (result < 0)
			result = result*(-1);
		while (result>0){
			if (afterdecimal == 0 && j==1)
				str[i++] = '.';
			else{
				str[i++] = (char)((result % 10) + 48);
				result = result / 10;
			}
			afterdecimal--;
		}
		if (result_temp < 0)
			str[i++] = '-';
		str[i] = '\0';
		strrev(str);
		
	
}

