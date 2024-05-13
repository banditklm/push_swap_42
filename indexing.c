/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:32:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 06:29:07 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_min(int min, t_stack **stack)
{
	t_stack	*tmp;
	int		next_min;

	tmp = *stack;
	next_min = INT_MAX;
	while (tmp)
	{
		if (tmp->content <= next_min && tmp->content > min)
			next_min = tmp->content;
		tmp = tmp->next;
	}
	return (next_min);
}

static void	set_min_index(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->content == stack_min(stack))
			tmp->index = 1;
		tmp = tmp->next;
	}
}

static void	set_max_index(t_stack **stack, int index)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->content == stack_max(stack))
			tmp->index = index;
		tmp = tmp->next;
	}
}

void	indexing(t_stack **stack)
{
	t_stack	*tmp;
	int		index;
	int		min;

	set_min_index(stack);
	(1) && (index = 2, tmp = *stack, min = stack_min(stack));
	while (tmp)
	{
		if (next_min(min, stack) == stack_max(stack))
			break ;
		if (tmp->content == next_min(min, stack))
		{
			tmp->index = index;
			index++;
			min = next_min(min, stack);
			tmp = *stack;
		}
		else
			tmp = tmp->next;
	}
	set_max_index(stack, index);
}
