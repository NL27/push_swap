/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:48:21 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 13:52:56 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

int	check_args(char **argv)
{
	alpha(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}

void	check_dup(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*start;

	start = *stack_a;
	tmp = *stack_a;
	while (start->next != *stack_a)
	{
		tmp = tmp->next;
		if ((tmp->nbr == start->nbr) && (tmp != start))
			ft_error();
		if ((tmp->nbr == start->nbr) && (tmp == start))
		{
			tmp = start->next;
			start = start->next;
			while (start != *stack_a)
			{
				tmp = tmp->next;
				if ((tmp->nbr == start->nbr) && (tmp != start))
					ft_error();
				if ((tmp->nbr == start->nbr) && (tmp == start))
					break ;
			}
		}
	}
}

bool	check_sort(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while ((tmp)->next != stack_a)
	{
		if ((tmp)->nbr < (tmp)->next->nbr)
			tmp = (tmp)->next;
		else
			return (false);
	}
	return (true);
}

void	check_size(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	while ((tmp)->next != *stack)
	{
		i++;
		tmp = (tmp)->next;
	}
}
