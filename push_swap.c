//right now, the code is not scalable or norminette compliant
//the to do list for tomorrow, is to make it norminette compliant
//and scalable. the ideas to do so is:

//1. use sizeof to find how many elements in the array of strings, instead of 
//hardcoded 4, so that if we need to add another flag, we can easily do it.

//2. in the function length_compare(), underflow might happen because of 
//strlen(arg) - 2, even though it is already avoided, but just to be sure,
//we need to add a guard for it, we need to check if strlen(arg) >= 2.

//3. we need to put the while loop in is_valid_argument() in a function.
//it needs to return the matching complexity enum number.

//4. syntax for norminette.

//5. proper header file.


#include <stdio.h>
#include "libft/libft.h"

//the enum needs to be in the header file
enum enComplexity{Simple, Medium, Complex, Bench, None, Invalid};

int length_compare(char *arg, char *str)
{
	if((strlen(arg) - 2) == strlen(str))
		return (1);
	return (0);
}

enum enComplexity is_valid_argument(char *arg)
{
	char *valid_arguments[] = {"simple", "medium", "complex", "bench"};
	int argument_number;

	argument_number = 0;
	if(arg == NULL)
		return (None);
	if(arg[0] == '-' && arg[1] == '-')
	{
		if(arg[2] == '\0')
			return (Invalid);
		while(argument_number < 4)
		{
			if(length_compare(arg, valid_arguments[argument_number]))
			{
				if(ft_strncmp((arg + 2), valid_arguments[argument_number], strlen(arg) - 2) == 0)
				{
					return (argument_number);
				}
			}
			argument_number ++;
		}
		return (Invalid);
	}
	else
		return (Invalid);
}

int main(int argc, char *argv[])
{
	int	arg_count;
	arg_count = 1;
    	if (argc < 2)
    	{
        	printf("Error\n");
        	return (0);
    	}
    	while(arg_count < argc)
	{

	}
    return (0);
}
