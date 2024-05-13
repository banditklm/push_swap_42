/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:01:04 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 07:35:25 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cas_1(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (is_in_bhalf(c, stack_b))
	{
		rrr(stack_a, stack_b);
	}
	else
		rra(stack_a, TRUE);
}

static void	cas_2(t_stack **stack_a, t_stack **stack_b, int c)
{
	pa(stack_a, stack_b);
	if ((*stack_a)->index != c && !is_in_bhalf(c, stack_b))
		rr(stack_b, stack_a);
	else
		ra(stack_a, TRUE);
}

static void	cas_3(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (ft_lstlast(*stack_a)->index == c)
		rrr(stack_a, stack_b);
	else
		rrb(stack_b, TRUE);
}

void	sort_num(t_stack **stack_a, t_stack **stack_b)
{
	int		c;

	c = 0;
	send_chunks(stack_a, stack_b);
	sort_3(stack_a);
	while (ft_lstsize(*stack_b))
	{
		c = (*stack_a)->index - 1;
		if ((*stack_b)->index == c)
			pa(stack_a, stack_b);
		else if (ft_lstlast(*stack_a)->index == c)
			cas_1(stack_a, stack_b, c);
		else if (ft_lstlast(*stack_a)->index == stack_max_index(stack_a)
			|| (*stack_b)->index > ft_lstlast(*stack_a)->index)
			cas_2(stack_a, stack_b, c);
		else if (is_in_bhalf(c, stack_b))
			cas_3(stack_a, stack_b, c);
		else
			rb(stack_b, TRUE);
	}
	if (!is_sorted(stack_a))
	{
		while (ft_lstlast(*stack_a)->index != stack_max_index(stack_a))
			rra(stack_a, TRUE);
	}
}
