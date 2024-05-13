/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:58:56 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/03 20:15:34 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, t_bool bool)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = *stack_a;
		tmp = tmp->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	if (bool)
		write (1, "sa\n", 3);
}

void	sb(t_stack **stack_b, t_bool bool)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp = *stack_b;
		tmp = tmp->next;
		(*stack_b)->next = (*stack_b)->next->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	if (bool)
		write (1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, FALSE);
	sb(stack_b, FALSE);
	write (1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_lstsize(*stack_b))
	{
		tmp = *stack_b;
		tmp2 = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		*stack_b = tmp2;
	}
	write (1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_lstsize(*stack_a))
	{
		tmp = *stack_a;
		tmp2 = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		*stack_a = tmp2;
	}
	write (1, "pb\n", 3);
}
