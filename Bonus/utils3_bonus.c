/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:50:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 20:44:48 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*stack_a;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->content = content;
	stack_a -> next = NULL;
	return (stack_a);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack		*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = (*lst)-> next;
			free(*lst);
			*lst = tmp;
		}
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	i++;
	return (i);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack		*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp -> next)
				tmp = tmp -> next;
			(tmp)-> next = new;
		}
		else
			*lst = new;
	}
}

int	is_sorted(t_stack **stack, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *stack;
	tmp1 = *stack;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->content > tmp1->content)
				return (0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (1 && !ft_lstsize(*stack_b));
}
