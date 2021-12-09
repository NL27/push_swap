/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:04:23 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 16:46:08 by nlenoch          ###   ########.fr       */
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

bool	last(t_stack **stack)
{
	if (*stack == (*stack)->next || (*stack)->next == NULL
		|| ((*stack) == (*stack)->prev && (*stack)->next == *stack))
		return (true);
	else
		return (false);
}

void	*ft_new_stack(t_stack **stack, int content)
{
	t_stack	*new_node;

	if (*stack == NULL)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->nbr = content;
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return (stack);
	}
	if ((*stack)->next == NULL)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->nbr = content;
		(*stack)->next = new_node;
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = *stack;
		*stack = new_node;
	}
	else
		stack = ft_add_to_stack(stack, content);
	return (stack);
}

void	*ft_add_to_stack(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*tmp1;

	tmp1 = *stack;
	new_node = malloc(sizeof(t_stack));
	new_node->nbr = content;
	tmp1 = tmp1->prev;
	tmp1->next = new_node;
	tmp1->next->prev = tmp1;
	tmp1 = tmp1->next;
	tmp1->next = *stack;
	(*stack)->prev = tmp1;
	*stack = new_node;
	return (stack);
}
