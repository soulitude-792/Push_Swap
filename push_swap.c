
#include <stdio.h>
#include "libft/libft.h"

enum e_flags
{
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_BENCH,
	FLAG_NONE,
	FLAG_INVALID
};

typedef struct stflag_entry
{
	char *flag_string;
	enum e_flags flag;
} t_flag_entry;

t_flag_entry flag_info[] = {
	{"simple", FLAG_SIMPLE},
	{"medium", FLAG_MEDIUM},
	{"complex", FLAG_COMPLEX},
	{"adaptive", FLAG_ADAPTIVE},
	{"bench", FLAG_BENCH}
};
enum e_flags is_valid_argument(char *arg)
{
	size_t	i;
	size_t	count;

	count = sizeof(flag_info) / sizeof(flag_info[0]);
	if (arg == NULL)
		return (FLAG_NONE);
	i = 0; 
	if (arg[0] == '-' && arg[1] == '-')
	{
		while(i < count)
		{
			if(ft_strncmp((arg + 2), flag_info[i].flag_string, ft_strlen(flag_info[i].flag_string) + 1) == 0)
			{
				return (flag_info[i].flag);
			}
			i++;
		}
	}
	return (FLAG_INVALID);
}

/*int main(int argc, char *argv[])
{	FLAG_MEDIUM,
	int	arg_count;
	arg_count = 1;
    	if (argc < 2)
        	return (0);
    	while(arg_count < argc)
	{

	}
    return (0);
}
int	main(void)
{
	printf("%d\n", is_valid_argument("--complex"));   
	printf("%d\n", is_valid_argument("--medi"));     
	printf("%d\n", is_valid_argument("--"));       
	printf("%d\n", is_valid_argument("5"));        
	printf("%d\n", is_valid_argument(NULL));        
	return (0);
}*/
