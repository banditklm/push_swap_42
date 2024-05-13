/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:56:41 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/11 02:41:01 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_bhalf(int c, t_stack **stack)
{
	int		i;
	int		half;
	t_stack	*tmp;

	i = 1;
	half = ft_lstsize(*stack) / 2;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == c)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i < half)
		return (0);
	else if (i >= half)
		return (1);
	return (0);
}

int	stack_max_index(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->index;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
