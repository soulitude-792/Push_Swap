#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (parse_args(argc, argv, &config) == -1)
	{
		printf("Error\n");
		return (1);
	}
	printf("mode:  %d\n", config.mode);
	printf("bench: %d\n", config.bench);
	return (0);
}