/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:04:47 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 17:26:59 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_print_stack(t_stack **stack)
// {
// 	t_stack	*tmp;
// 	t_stack	*tmp1;

// 	tmp = *stack;
// 	tmp1 = *stack;
// 	printf("tmp->nbr : %ld\n", tmp->nbr);
// 	tmp = tmp->next;
// 	while (tmp != tmp1)
// 	{
// 		printf("tmp->nbr : %ld\n", tmp->nbr);
// 		tmp = tmp->next;
// 	}
// }

void	check_fct(t_stack **stack)
{
	check_size(stack);
	check_dup(stack);
	check_init(stack);
}

int	main(int argc, char **argv)
{
	int		num;
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	else if (!check_args(argv))
		ft_error();
	list_args(argv, &stack_a);
	if (stack_a != NULL && (stack_a)->next != NULL)
		if (!check_sort(stack_a))
			check_fct(&stack_a);
	while (stack_a != NULL)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	system ("leaks push_swap");
	return (0);
}
