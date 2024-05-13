/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:29:35 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 10:36:21 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_sign(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-')
				&& (str[i][j + 1] == '+' || str[i][j + 1] == '-'
				|| str[i][j + 1] == ' ' || str[i][j + 1] == '\0'))
				return (0);
			else if ((str[i][j] >= '0' && str[i][j] <= '9')
				&& (str[i][j + 1] == '+' || str[i][j + 1] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_dup(t_stack *stack_a)
{
	t_stack	*tmp_stk1;
	t_stack	*tmp_stk2;

	tmp_stk1 = stack_a;
	tmp_stk2 = stack_a;
	while (tmp_stk1)
	{
		tmp_stk2 = tmp_stk1->next;
		while (tmp_stk2)
		{
			if (tmp_stk1->content == tmp_stk2->content)
				return (0);
			tmp_stk2 = tmp_stk2->next;
		}
		tmp_stk1 = tmp_stk1->next;
	}
	return (1);
}

static void	fill_stack_a(char **str, t_stack **stack_a)
{
	int			j;
	t_stack		*tmp_stack;

	j = 0;
	if (ft_atoi(str[j]) < INT_MIN || ft_atoi(str[j]) > INT_MAX)
		ft_error("Error", *stack_a, 1, str);
	tmp_stack = ft_lstnew(ft_atoi(str[j]));
	if (!tmp_stack)
		ft_error(NULL, tmp_stack, 1, NULL);
	ft_lstadd_back(stack_a, tmp_stack);
	j++;
	while (str[j])
	{
		if (ft_atoi(str[j]) < INT_MIN || ft_atoi(str[j]) > INT_MAX)
			ft_error("Error", *stack_a, 1, str);
		tmp_stack = ft_lstnew(ft_atoi(str[j]));
		if (!tmp_stack)
			ft_error(NULL, tmp_stack, 1, NULL);
		ft_lstadd_back(stack_a, tmp_stack);
		j++;
	}
}

static void	get_stack_a(char **args, t_stack **stack)
{
	char		**tmp;
	int			i;

	i = 1;
	while (args[i])
	{
		tmp = ft_split(args[i], ' ');
		if (!tmp)
			ft_error("Error", *stack, 1, tmp);
		if (!count_nmbrs(tmp))
			ft_error("Error", *stack, 1, tmp);
		fill_stack_a(tmp, stack);
		ft_free(NULL, tmp, NULL);
		i++;
	}
}

void	parser_check(int ac, char **args, t_stack **stack_a)
{
	if (ac == 1)
		exit(0);
	if (!is_num(args))
		ft_error("Error", NULL, 1, NULL);
	if (!check_sign(args))
		ft_error("Error", NULL, 1, NULL);
	get_stack_a(args, stack_a);
	if (!(check_dup(*stack_a)))
		ft_error("Error", *stack_a, 1, NULL);
}
