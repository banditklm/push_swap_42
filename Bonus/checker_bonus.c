/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:43:36 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 20:51:26 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**instr;

	stack_a = NULL;
	stack_b = NULL;
	parser_check(ac, av, &stack_a);
	instr = get_instr(&stack_a, &stack_b);
	if (instr)
		exec_instr(&stack_a, &stack_b, instr);
	if (is_sorted(&stack_a, &stack_b))
		write(1, "OK\n", 3);
	else if (!is_sorted(&stack_a, &stack_b))
		write(1, "KO\n", 3);
	ft_error(NULL, stack_a, 0, instr);
}
