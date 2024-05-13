/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:39:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/11 02:12:44 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
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
