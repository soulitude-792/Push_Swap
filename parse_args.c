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

static int	handle_arg(char *arg, t_config *config, t_stack *a)
{
	enum e_flags	flag;

	flag = is_valid_flag(arg);
	if (flag == FLAG_INVALID)
		return (-1);
	if (flag == FLAG_BENCH)
		config->bench = 1;
	else if (flag != NOT_A_FLAG)
		config->mode = flag;
	else if (flag == NOT_A_FLAG)
	{
		if(parse_nums(arg, a) == -1)
			return (-1);
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_config *config, t_stack *a)
{
	int	i;
	int	total;
	
	config->mode = FLAG_ADAPTIVE;
	config->bench = 0;
	total = count_total(argc, argv);
	a->data = malloc(sizeof(int) * total);
	if(a->data == NULL)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if(handle_arg(argv[i], config, a) == -1)
			return (-1);
		i++;
	}
	return (0);
}