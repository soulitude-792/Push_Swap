/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imigdady <imigdady@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:02:14 by imigdady          #+#    #+#             */
/*   Updated: 2026/11/23 17:31:41 by imigdady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

enum e_flags	is_valid_flag(char *arg)
{
	if (arg == NULL || arg[0] != '-' || arg[1] != '-')
		return (NOT_A_FLAG);
	arg += 2;
	if (ft_strncmp(arg, "simple", 7) == 0)
		return (FLAG_SIMPLE);
	if (ft_strncmp(arg, "medium", 7) == 0)
		return (FLAG_MEDIUM);
	if (ft_strncmp(arg, "complex", 8) == 0)
		return (FLAG_COMPLEX);
	if (ft_strncmp(arg, "adaptive", 9) == 0)
		return (FLAG_ADAPTIVE);
	if (ft_strncmp(arg, "bench", 6) == 0)
		return (FLAG_BENCH);
	return (FLAG_INVALID);
}

int	parse_num(char	*arg)
{

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
		else if (flag == NOT_A_FLAG)
			parse_num(argv[i]);
		i++;
	}
	return (0);
}


