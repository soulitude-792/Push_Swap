#include "push_swap.h"

void free_all(char **splitted_args)
{
    int i;

    i = 0;
    while(splitted_args[i] != NULL)
    {
        free(splitted_args[i]);
        i++;
    }
    free(splitted_args);
}

static int is_number(char *arg)
{
    int sign;
    int i;
    int res;

    sign = 1;
    i = 0;
    res = 0;
    if
}

static int overflow_check(char *arg, int *value)
{}

static int duplicate_check(t_stack *data, int value, t_stack *size)
{}

static int num_checker(char **splitted_args, t_stack *a)
{
    int i;
    int value;

    i = 0;
        while(splitted_args[i] != NULL)
    {
        if(!is_number(splitted_args[i]))
            return (-1);
        if(!overflow_check(splitted_args[i], &value))
            return (-1);
        if(duplicate_check(a->data, value,a->size))
            return (-1);
        a->data[a->size] = value;
        a->size++;
        i++;
    }
}

int count_total(int argc, char **argv)
{
    int i;
    int total;

    total = 0;
    i = 1;
    while(i < argc)
    {
        if(is_valid_flag(argv[i]) == NOT_A_FLAG)
        {
            total = total + count_words(argv[i]);
        }
        i++;
    }
    return (total);
}

int count_words(char *arg)
{
    int in_word;
    int count;

    in_word = 0;
    count = 0;
    while (*arg)
    {
        if (*arg != ' ' && in_word == 0)
        {
            count++;
            in_word = 1;
        }
        if (*arg == ' ')
            in_word = 0;
        arg++;
    }
    return (count);
}

int parse_nums(char *arg, t_stack *a)
{
    int ret;
    char **splitted_args;

    ret = 0;
    splitted_args = ft_split(arg, ' ');
    if(splitted_args == NULL)
        return (-1);
    if(splitted_args[0] == NULL)
    {
        free_all(splitted_args);
        return (-1);
    }
    ret = num_checker(splitted_args, a);
    free_all(splitted_args);
    return (ret);
}