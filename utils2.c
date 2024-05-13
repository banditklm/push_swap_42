/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:06:05 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/11 02:15:05 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	stack_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	stack_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	is_sorted(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = *stack;
	while (tmp && (i == tmp->index))
	{
		if (tmp->next == NULL)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
