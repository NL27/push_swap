/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:33:57 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/05 19:02:50 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack_a)->next;
	tmp2 = (*stack_a)->prev;
	(*stack_a)->next = tmp1->next;
	(*stack_a)->prev = tmp1;
	tmp1->next = tmp1->prev;
	tmp1->prev = tmp2;
	tmp1->next->prev = tmp1->prev;
	tmp2->next = tmp1;
	*stack_a = tmp1;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

t_stack	**rotate(t_stack **stack_1, t_stack **stack_2, char c)
{
	*stack_1 = (*stack_1)->next;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == 'r')
	{
		write (1, "rr\n", 3);
		rotate(stack_2, stack_1, ' ');
	}
	return (stack_1);
}

t_stack	**rrotate(t_stack **stack_1, t_stack **stack_2, char c)
{
	*stack_1 = (*stack_1)->prev;
	if (c == 'a')
	{
		write(1, "rra\n", 4);
		return (stack_1);
	}
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else if (c == 'r')
	{
		write (1, "rrr\n", 4);
		rrotate(stack_2, stack_1, ' ');
	}
	return (*(&stack_2));
}

void	del_node(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next != *head)
		tmp = tmp->next;
	tmp->next = (*head)->next;
	(*head)->next->prev = tmp;
	free(*head);
	*head = tmp->next;
}

void	push(t_stack **stack_to, t_stack **stack_from, char c)
{
	if (c == 'a')
	{
		ft_add_to_a(stack_from, stack_to);
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		ft_add_to_b(stack_from, stack_to);
		write(1, "pb\n", 3);
	}
	else if (c == 'A')
	{
		ft_add_big_to_a(stack_from, stack_to);
		write(1, "pa\n", 3);
	}
	else if (c == 'B')
	{
		ft_add_big_to_b(stack_from, stack_to);
		write(1, "pb\n", 3);
	}
}
