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