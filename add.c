/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:08:05 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/05 19:15:09 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_a(t_stack **stack, t_stack **stack_new)
{
	int		max;

	max = get_max(*stack);
	ft_new_stack(stack_new, max);
	if (!last(stack))
		del_node(stack);
	else
		*stack = NULL;
}

void	ft_add_big_to_a(t_stack **stack, t_stack **stack_new)
{
	int		nbr;

	nbr = (*stack)->nbr;
	ft_new_stack(stack_new, nbr);
	if (!last(stack))
		del_node(stack);
	else
		*stack = NULL;
}

void	ft_add_big_to_b(t_stack **stack, t_stack **stack_new)
{
	int		nbr;

	nbr = (*stack)->nbr;
	ft_new_stack(stack_new, nbr);
	del_node(stack);
}

void	ft_add_to_b(t_stack **stack, t_stack **stack_new)
{
	int		min;

	min = get_min(*stack);
	ft_new_stack(stack_new, min);
	del_node(stack);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	t_stack	*tmp1;

	tmp1 = *stack;
	if (tmp1 == NULL)
	{
		stack_new->next = NULL;
		stack_new->prev = NULL;
		*stack = stack_new;
	}
	else if (tmp1->next == NULL)
	{
		tmp1->next = stack_new;
		tmp1->prev = stack_new;
		stack_new->prev = tmp1;
		stack_new->next = tmp1;
	}
	else
	{
		tmp1 = tmp1->prev;
		tmp1->next = stack_new;
		tmp1->next->prev = tmp1;
		tmp1 = tmp1->next;
		tmp1->next = *stack;
		(*stack)->prev = tmp1;
	}	
}
