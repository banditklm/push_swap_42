/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:33:31 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 06:21:07 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free(t_stack *stack_a, char **str, char *s)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	if (s)
		free(s);
	ft_lstclear(&stack_a);
}

void	ft_error(char *str, t_stack *stack_a, int b, char **s)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write (2, &str[i], 1);
			i++;
		}
		write (2, "\n", 1);
	}
	ft_free(stack_a, s, NULL);
	exit (b);
}

void	ft_error2(char *str, t_stack *stack_a, int b, char *s)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write (2, &str[i], 1);
			i++;
		}
		write (2, "\n", 1);
	}
	ft_free(stack_a, NULL, s);
	exit (b);
}

int	count_nmbrs(char **str)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (str[++i])
	{
		j = 0;
		len = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
		{
			len++;
			j++;
		}
		while (str[i][j] == '0')
			j++;
		while (str[i][j])
		{
			j++;
			len++;
		}
		if (len >= 12)
			return (0);
	}
	return (i);
}

int	is_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		if (!str[i][j])
			return (0);
		while (str[i][j])
		{
			if (!(str[i][j] == ' ' || str[i][j] == '+'
				|| str[i][j] == '-' || (str[i][j] >= '0' && str[i][j] <= '9')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
