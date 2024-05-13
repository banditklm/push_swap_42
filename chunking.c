/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:11:24 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 06:30:10 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_chunk1(t_stack **stack_a, t_stack **stack_b, int p1, int p2)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while ((ft_lstsize(*stack_a) > 3) && (i < p1))
	{
		if (tmp->index <= p1)
		{
			pb(stack_b, stack_a);
			i++;
			if (tmp->index <= p2)
			{
				if ((*stack_a)->index > p1)
					rr(stack_b, stack_a);
				else
					rb(stack_b, TRUE);
			}
		}
		else
			ra(stack_a, TRUE);
		tmp = *stack_a;
	}
}

static void	send_chunk2(t_stack **stack_a, t_stack **stack_b, int p1, int p2)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while ((ft_lstsize(*stack_a) > 3) && i < (p1 / 2))
	{
		if (tmp->index <= p1)
		{
			pb(stack_b, stack_a);
			i++;
			if (tmp->index <= p2)
			{
				if ((*stack_a)->index > p1)
					rr(stack_b, stack_a);
				else
					rb(stack_b, TRUE);
			}
		}
		else
			ra(stack_a, TRUE);
		tmp = *stack_a;
	}
}

static void	send_chunk3(t_stack **stack_a, t_stack **stack_b, int p1, int p2)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while ((ft_lstsize(*stack_a) > 3) && (i < (p1 / 3)))
	{
		if (tmp->index <= p1)
		{
			pb(stack_b, stack_a);
			i++;
			if (tmp->index <= p2)
			{
				if ((*stack_a)->index > p1)
					rr(stack_b, stack_a);
				else
					rb(stack_b, TRUE);
			}
		}
		else
			ra(stack_a, TRUE);
		tmp = *stack_a;
	}
}

static void	send_chunk4(t_stack **stack_a, t_stack **stack_b, int p2, int b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (ft_lstsize(*stack_a) > 3)
	{
		if (tmp->index <= b)
		{
			if (tmp->index <= p2)
			{
				pb(stack_b, stack_a);
				rb(stack_b, TRUE);
			}
			else
				pb(stack_b, stack_a);
		}
		else
			ra(stack_a, TRUE);
		tmp = *stack_a;
	}
}

void	send_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int		pivot1;
	int		pivot2;
	int		base;

	base = ft_lstsize(*stack_a) - 3;
	pivot1 = ft_lstsize(*stack_a) / 4;
	pivot2 = ft_lstsize(*stack_a) / 8;
	send_chunk1(stack_a, stack_b, pivot1, pivot2);
	pivot1 *= 2;
	pivot2 *= 3;
	send_chunk2(stack_a, stack_b, pivot1, pivot2);
	pivot1 = pivot1 * 3 / 2;
	pivot2 = pivot2 * 5 / 3;
	send_chunk3(stack_a, stack_b, pivot1, pivot2);
	pivot2 = pivot2 * 7 / 5;
	send_chunk4(stack_a, stack_b, pivot2, base);
}
