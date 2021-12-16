/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:58:57 by nlenoch           #+#    #+#             */
/*   Updated: 2021/12/09 13:43:47 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}
