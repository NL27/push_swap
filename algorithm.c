/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:31:21 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 17:27:29 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int **arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*arr)[i] > (*arr)[j])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sort_arr(t_stack **stack, int size)
{
	t_stack	**tmp;
	int		i;
	int		*arr;

	i = 0;
	arr = malloc(size * sizeof(int));
	tmp = stack;
	while (i != size)
	{
		arr[i] = (*tmp)->nbr;
		*tmp = (*tmp)->next;
		i++;
	}
	bubble_sort(&arr, size);
	return (arr);
}

void	change_list(t_stack **stack, int *arr, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (i != size)
	{
		if (arr[i] == (tmp)->nbr && !tmp->was_replaced)
		{
			(tmp)->nbr = i;
			tmp->was_replaced = true;
			i++;
		}
		tmp = (tmp)->next;
	}
}

void	radix_sort(t_stack **stack_a, int size, int i)
{
	t_stack	*stack_b;
	int		j;
	int		max_size;
	int		max_bits;

	stack_b = NULL;
	max_size = size - 1;
	max_bits = 0;
	while ((max_size >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((*stack_a)->nbr & (1 << i))
				rotate(stack_a, NULL, 'a');
			else
				push(&stack_b, stack_a, 'B');
		}
		while (stack_b != NULL)
			push(stack_a, &stack_b, 'A');
	}
}

void	sort_big(t_stack **stack_a, int size)
{
	int	*arr;
	int	i;

	i = -1;
	arr = sort_arr(stack_a, size);
	change_list(stack_a, arr, size);
	free (arr);
	radix_sort(stack_a, size, i);
}
