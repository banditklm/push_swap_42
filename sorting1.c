/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:31:05 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/11 01:59:41 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack, TRUE);
}

void	sort_3(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
	{
		ra(stack, TRUE);
	}
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		rra(stack, TRUE);
	}
	if ((*stack)->content > (*stack)->next->content)
		sa(stack, TRUE);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, t_bool b)
{
	if ((*stack_a)->content == stack_min(stack_a))
		pb(stack_b, stack_a);
	else if ((*stack_a)->next->content == stack_min(stack_a))
	{
		sa(stack_a, TRUE);
		pb(stack_b, stack_a);
	}
	else if ((*stack_a)->next->next->content == stack_min(stack_a))
	{
		rra(stack_a, TRUE);
		rra(stack_a, TRUE);
		pb(stack_b, stack_a);
	}
	else
	{
		rra(stack_a, TRUE);
		pb(stack_b, stack_a);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if (b)
		pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->content == stack_min(stack_a))
		pb(stack_b, stack_a);
	else if ((*stack_a)->next->content == stack_min(stack_a))
	{
		sa(stack_a, TRUE);
		pb(stack_b, stack_a);
	}
	else if ((*stack_a)->next->next->content == stack_min(stack_a))
	{
		ra(stack_a, TRUE);
		sa(stack_a, TRUE);
		pb(stack_b, stack_a);
	}
	else
	{
		rra(stack_a, TRUE);
		if ((*stack_a)->content == stack_min(stack_a))
			pb(stack_b, stack_a);
		else
		{
			rra(stack_a, TRUE);
			pb(stack_b, stack_a);
		}
	}
	sort_4(stack_a, stack_b, TRUE);
}
