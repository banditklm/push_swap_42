/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:53 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 06:26:23 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
	t_bool			bool;

}	t_stack;

void		parser(int ac, char **av, t_stack **stack_a);
char		**ft_split(char *s, char c);
int			ft_strlen(char *str);
t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
long		ft_atoi(const char *str);
void		ft_lstclear(t_stack **lst);
int			count_nmbrs(char **str);
void		ft_free(t_stack *stack_a, char **str);
void		ft_error(char *str, t_stack *stack_a, int b, char **s);
int			is_num(char **str);
int			ft_lstsize(t_stack *lst);
void		sa(t_stack **stack_a, t_bool bool);
void		sb(t_stack **stack_b, t_bool bool);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a, t_bool bool);
void		rb(t_stack **stack_b, t_bool bool);
void		rr(t_stack **stack_b, t_stack **stack_a);
void		rra(t_stack **stack_a, t_bool bool);
void		rrb(t_stack **stack_b, t_bool bool);
void		rrr(t_stack **stack_b, t_stack **stack_a);
int			stack_max(t_stack **stack);
int			stack_min(t_stack **stack);
int			next_min(int min, t_stack **stack);
void		indexing(t_stack **stack);
void		sort_2(t_stack **stack);
void		sort_3(t_stack **stack);
void		sort_4(t_stack **stack_a, t_stack **stack_b, t_bool b);
void		sort_5(t_stack **stack_a, t_stack **stack_b);
void		send_chunks(t_stack **stack_a, t_stack **stack_b);
void		sort_num(t_stack **stack_a, t_stack **stack_b);
int			is_in_bhalf(int c, t_stack **stack);
int			is_sorted(t_stack **stack);
int			stack_max_index(t_stack **stack);

#endif