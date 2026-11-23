#include "push_swap.h"

typedef struct s_flag_entry
{
	char			*flag_string;
	enum e_flags	flag;
}	t_flag_entry;

static const t_flag_entry	g_flag_info[] = {
{"simple", FLAG_SIMPLE},
{"medium", FLAG_MEDIUM},
{"complex", FLAG_COMPLEX},
{"adaptive", FLAG_ADAPTIVE},
{"bench", FLAG_BENCH}
};

enum e_flags	is_valid_flag(char *arg)
{
	size_t	i;
	size_t	count;

	if (arg == NULL || arg[0] != '-' || arg[1] != '-')
		return (NOT_A_FLAG);
	count = sizeof(g_flag_info) / sizeof(g_flag_info[0]);
	i = 0;
	while (i < count)
	{
		if (ft_strncmp(arg + 2, g_flag_info[i].flag_string,
				ft_strlen(g_flag_info[i].flag_string) + 1) == 0)
			return (g_flag_info[i].flag);
		i++;
	}
	return (FLAG_INVALID);
}

int	parse_args(int argc, char **argv, t_config *config)
{
	int				i;
	enum e_flags	flag;

	config->mode = FLAG_ADAPTIVE;
	config->bench = 0;
	i = 1;
	while (i < argc)
	{
		flag = is_valid_flag(argv[i]);
		if (flag == FLAG_INVALID)
			return (-1);
		if (flag == FLAG_BENCH)
			config->bench = 1;
		else if (flag != NOT_A_FLAG)
			config->mode = flag;
		i++;
	}
	return (0);
}