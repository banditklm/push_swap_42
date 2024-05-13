/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:54:18 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/11 01:50:51 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, t_bool bool)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	if (ft_lstsize(*stack_a) >= 2)
	{
		(1) && (i = ft_lstsize(*stack_a), i--);
		tmp2 = *stack_a;
		tmp = *stack_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		while (--i)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
	}
	if (bool)
		write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, t_bool bool)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	if (ft_lstsize(*stack_b) >= 2)
	{
		(1) && (i = ft_lstsize(*stack_b), i--);
		tmp2 = *stack_b;
		tmp = *stack_b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		while (--i)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
	}
	if (bool)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack_b, t_stack **stack_a)
{
	rra(stack_a, FALSE);
	rrb(stack_b, FALSE);
	write (1, "rrr\n", 4);
}
