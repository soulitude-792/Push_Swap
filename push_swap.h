#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

enum e_flags
{
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_BENCH,
	NOT_A_FLAG,
	FLAG_INVALID
};

typedef struct  s_config
{
    enum e_flags    mode;
    int             bench;
}   t_config;

enum e_flags	is_valid_flag(char *arg);
int				parse_args(int argc, char **argv, t_config *config);

#endif