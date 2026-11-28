#include "push_swap.h"

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
    int i;
    int value;
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
    i = 0;
    while(splitted_args[i] != NULL)
    {
        if(!is_number(splitted_args[i]))
        {
            ret = -1;
            break;
        }
        if(!overflow_check(splitted_args[i], &value))
        {
            ret = -1;
            break;
        }
        if(duplicate_check(a->data, value,a->size))
        {
            ret = -1;
            break;
        }
        a->data[a->size] = value;
        a->size++;
        i++;
    }
    free_all(splitted_args);
    return (ret);
}