/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imigdady <imigdady@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:02:20 by imigdady          #+#    #+#             */
/*   Updated: 2026/11/23 17:33:21 by imigdady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

typedef struct s_config
{
	enum e_flags	mode;
	int				bench;
}	t_config;

enum e_flags	is_valid_flag(char *arg);
int				parse_args(int argc, char **argv, t_config *config, t_stack *a);
int 			parse_args(int argc, char **argv, t_config *config, t_stack *a);
int				count_total(int argc, char **argv);
int				count_words(char *arg);
int				parse_nums(char	*arg, t_stack *a);

#endif
