/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:31:53 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 15:50:52 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_stack **stack_a, int size)
{
	t_stack	**t;

	t = stack_a;
	while (check_sort(*stack_a) != true)
	{
		if ((*t)->nbr < (*t)->next->nbr && (*t)->nbr < (*t)->prev->nbr)
			swap(stack_a, 'a');
		else if (((*t)->nbr > (*t)->next->nbr && (*t)->nbr > (*t)->prev->nbr)
			|| ((*t)->nbr < (*t)->next->nbr && (*t)->nbr > (*t)->prev->nbr))
			rotate(stack_a, NULL, 'a');
		else if ((*t)->nbr > (*t)->next->nbr && (*t)->nbr < (*t)->prev->nbr)
			swap(stack_a, 'a');
		else if ((*t)->nbr < (*t)->next->nbr && (*t)->nbr > (*t)->prev->nbr)
			rotate(stack_a, NULL, 'a');
	}
}

static void	sort_medium(t_stack **stack_a, int size)
{
	int		min;
	t_stack	*stack_b;

	stack_b = NULL;
	while (size-- > 3)
	{
		min = get_min(*stack_a);
		if ((*stack_a)->nbr == min)
		{
			push(&stack_b, stack_a, 'b');
			min = get_min(*stack_a);
		}
		while ((*stack_a)->nbr != min)
		{
			if ((*stack_a)->prev->nbr == min)
				stack_a = rrotate(stack_a, &stack_b, 'a');
			else
				stack_a = rotate(stack_a, &stack_b, 'a');
		}
		push(&stack_b, stack_a, 'b');
	}
	sort_small(stack_a, 3);
	while (stack_b != NULL)
		push(stack_a, &stack_b, 'a');
}

void	check_init(t_stack **stack_a)
{
	int	size;

	size = ft_stacksize(stack_a);
	if (size == 2)
		swap(stack_a, 'a');
	else if (size == 3)
		sort_small(stack_a, size);
	else if (size <= 5)
		sort_medium(stack_a, size);
	else
		sort_big(stack_a, size);
}

void	alpha(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}
