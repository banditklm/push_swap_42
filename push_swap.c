/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:35 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 20:47:32 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parser(ac, av, &stack_a);
	indexing(&stack_a);
	if (ft_lstsize(stack_a) == 1 || is_sorted(&stack_a))
	{
		ft_free(stack_a, NULL);
		return (0);
	}
	if (ft_lstsize(stack_a) == 2)
		sort_2(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_3(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		sort_4(&stack_a, &stack_b, FALSE);
	else if (ft_lstsize(stack_a) == 5)
		sort_5(&stack_a, &stack_b);
	else
		sort_num(&stack_a, &stack_b);
	ft_free(stack_a, NULL);
	ft_free(stack_b, NULL);
}
