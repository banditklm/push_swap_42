/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:51:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 20:52:11 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_line(char *line)
{
	if (!ft_strncmp("sa\n", line, ft_strlen_get(line))
		|| !ft_strncmp("sb\n", line, ft_strlen_get(line))
		|| !ft_strncmp("ss\n", line, ft_strlen_get(line))
		|| !ft_strncmp("pa\n", line, ft_strlen_get(line))
		|| !ft_strncmp("pb\n", line, ft_strlen_get(line))
		|| !ft_strncmp("ra\n", line, ft_strlen_get(line))
		|| !ft_strncmp("rb\n", line, ft_strlen_get(line))
		|| !ft_strncmp("rr\n", line, ft_strlen_get(line))
		|| !ft_strncmp("rra\n", line, ft_strlen_get(line))
		|| !ft_strncmp("rrb\n", line, ft_strlen_get(line))
		|| !ft_strncmp("rrr\n", line, ft_strlen_get(line)))
		return (1);
	else
		return (0);
}

char	*get_first_inst(char **buff, t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	*buff = NULL;
	line = get_next_line(0);
	if (!line)
	{
		if (ft_lstsize(*stack_a) == 1 || is_sorted(stack_a, stack_b))
			write(1, "OK\n", 3);
		else if (!is_sorted(stack_a, stack_b))
			write(1, "KO\n", 3);
		ft_error(NULL, *stack_a, 0, NULL);
	}
	if (!check_line(line))
		ft_error2("Error", *stack_a, 1, line);
	*buff = ft_strjoin(*buff, line);
	if (!(*buff))
		ft_error2("Error", *stack_a, 1, line);
	return (line);
}

char	**get_instr(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	char	*buff;
	char	**instr;

	(1) && (buff = NULL, line = get_first_inst(&buff, stack_a, stack_b));
	while (line)
	{
		free(line);
		line = get_next_line(0);
		if (!check_line(line))
		{
			free(line);
			ft_error2("Error", *stack_a, 1, buff);
		}
		else
		{
			buff = ft_strjoin(buff, line);
			if (!buff)
				ft_error2("Error", *stack_a, 1, line);
		}
	}
	instr = ft_split(buff, '\n');
	if (!instr)
		ft_error("Error", *stack_a, 1, instr);
	return (free(buff), instr);
}

void	exec_instr2(t_stack **a, t_stack **b, char **ins, int *i)
{
	if (!ft_strncmp("ra\n", ins[*i], ft_strlen_get(ins[*i])))
		ra(a, FALSE);
	else if (!ft_strncmp("rb\n", ins[*i], ft_strlen_get(ins[*i])))
		rb(b, FALSE);
	else if (!ft_strncmp("rr\n", ins[*i], ft_strlen_get(ins[*i])))
		rr(b, a);
	else if (!ft_strncmp("rra\n", ins[*i], ft_strlen_get(ins[*i])))
		rra(a, FALSE);
	else if (!ft_strncmp("rrb\n", ins[*i], ft_strlen_get(ins[*i])))
		rrb(b, FALSE);
	else if (!ft_strncmp("rrr\n", ins[*i], ft_strlen_get(ins[*i])))
		rrr(b, a);
}

void	exec_instr(t_stack **stack_a, t_stack **stack_b, char **instr)
{
	int	i;

	i = -1;
	while (instr[++i])
	{
		if (!ft_strncmp("sa\n", instr[i], ft_strlen_get(instr[i])))
			sa(stack_a, FALSE);
		else if (!ft_strncmp("sb\n", instr[i], ft_strlen_get(instr[i])))
			sb(stack_b, FALSE);
		else if (!ft_strncmp("ss\n", instr[i], ft_strlen_get(instr[i])))
			ss(stack_a, stack_b);
		else if (!ft_strncmp("pa\n", instr[i], ft_strlen_get(instr[i])))
			pa(stack_a, stack_b);
		else if (!ft_strncmp("pb\n", instr[i], ft_strlen_get(instr[i])))
			pb(stack_b, stack_a);
		exec_instr2(stack_a, stack_a, instr, &i);
	}
}
