/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:04:56 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 16:44:58 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
	bool			was_replaced;
}	t_stack;

			/* Operations */
void		swap(t_stack **stack_a, char c);
t_stack		**rotate(t_stack **stack_1, t_stack **stack_2, char c);
t_stack		**rrotate(t_stack **stack_1, t_stack **stack_2, char c);
void		push(t_stack **stack_to, t_stack **stack_from, char c);

			/* Sorting */
void		sort_big(t_stack **stack_a, int size);

			/* Checks */
void		ft_error(void);
int			check_args(char **argv);
bool		check_sort(t_stack *stack_a);
void		check_size(t_stack **stack);
void		check_init(t_stack **stack_a);
void		check_fct(t_stack **stack);
void		check_dup(t_stack **stack_a);

			/* Utils */
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
bool		last(t_stack **stack);
int			space(int c);
int			digit(int c);
int			sign(int c);
void		alpha(char **argv);
int			ft_isalpha(int c);
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
void		list_args(char **argv, t_stack **stack_a);
int			mydigit(char c);

			/* Stack */
t_stack		*ft_stack_new(long content);
int			ft_stacksize(t_stack **stack);
void		*ft_new_stack(t_stack **stack, int content);
void		*ft_add_to_stack(t_stack **stack, int content);
void		del_node(t_stack **head);

			/* Add */
void		ft_add_back(t_stack **stack, t_stack *stack_new);
void		ft_add_to_a(t_stack **stack, t_stack **stack_new);
void		ft_add_to_b(t_stack **stack, t_stack **stack_new);
void		ft_add_big_to_a(t_stack **stack, t_stack **stack_new);
void		ft_add_big_to_b(t_stack **stack, t_stack **stack_new);

#endif