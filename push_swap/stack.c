/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:04:23 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/16 23:43:39 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(long content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	new->was_replaced = false;
	return (new);
}

int	ft_stacksize(t_stack **stack)
{
	t_stack	*tmp;
	int		count;

	if (*stack == NULL)
		return (0);
	tmp = *stack;
	count = 1;
	while (tmp->next != *stack)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_new_stack(t_stack **stack_new, t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack_new == NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = tmp->prev;
		(*stack)->prev->next = *stack;
		*stack_new = tmp;
		(*stack_new)->next = *stack_new;
		(*stack_new)->prev = *stack_new;
	}
	else
		ft_add_to_stack(stack_new, stack);
}

void	ft_add_to_stack(t_stack **stack_new, t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if ((*stack)->next == *stack)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = tmp->prev;
		(*stack)->prev->next = *stack;
	}
	tmp->prev = (*stack_new)->prev;
	tmp->next = (*stack_new);
	(*stack_new)->prev->next = tmp;
	(*stack_new)->prev = tmp;
	*stack_new = tmp;
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
