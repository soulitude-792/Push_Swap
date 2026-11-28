/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imigdady <imigdady@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:02:08 by imigdady          #+#    #+#             */
/*   Updated: 2026/11/23 17:02:09 by imigdady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		a;

	a.data = NULL;
	a.size = 0;

	parse_args(argc, argv, &config, &a);
	
	return (0);
}
