/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:09:56 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/08 21:15:47 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack;
	min = (tmp)->nbr;
	tmp = (tmp)->next;
	while (tmp != stack)
	{
		if ((tmp)->nbr < min)
			min = (tmp)->nbr;
		tmp = (tmp)->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = (tmp)->nbr;
	tmp = (tmp)->next;
	if (tmp == NULL)
		return (max);
	while (tmp != stack)
	{
		if ((tmp)->nbr > max)
			max = (tmp)->nbr;
		tmp = (tmp)->next;
	}
	return (max);
}

void	list_args(char **argv, t_stack **stack_a)
{
	char	**splitted;
	long	i;
	long	j;

	i = 1;
	while (argv[i] != NULL)
	{
		splitted = ft_split(argv[i], ' ');
		j = 0;
		while (splitted[j])
		{
			ft_add_back(&(*stack_a), ft_stack_new(ft_atoi(splitted[j])));
			free(splitted[j]);
			j++;
		}
		free(splitted);
		i++;
	}
}

void	isonlydigit(const char *str)
{
	int	i;

	i = 0;
	while (digit(*str))
	{
		if (!digit(*str))
			ft_error();
		if (i == 10)
			ft_error();
		str++;
		i++;
	}
}

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str) == '-' || (*str) == '+')
	{
		if (*str == '+')
			sign = 1;
		else
			sign = -1;
		++str;
	}
	isonlydigit(str);
	while (digit(*str) && (*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		ft_error();
	return (sign * result);
}
