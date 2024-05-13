/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:45:09 by kelmounj          #+#    #+#             */
/*   Updated: 2024/05/12 21:03:13 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef int	t_bool;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
	t_bool			bool;

}	t_stack;

char	*get_next_line(int fd);
size_t	ft_strlen_get(const	char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
void	parser_check(int ac, char **args, t_stack **stack_a);
void	ft_free(t_stack *stack_a, char **str, char *s);
void	ft_error(char *str, t_stack *stack_a, int b, char **s);
void	ft_error2(char *str, t_stack *stack_a, int b, char *s);
int		count_nmbrs(char **str);
int		is_num(char **str);
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
long	ft_atoi(const char *str);
int		is_sorted(t_stack **stack, t_stack **stack_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_stack	*ft_lstnew(int content);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		stack_min(t_stack **stack);
int		stack_max(t_stack **stack);
int		check_line(char *line);
char	*get_first_inst(char **buff, t_stack **stack_a, t_stack **stack_b);
char	**get_instr(t_stack **stack_a, t_stack **stack_b);
void	exec_instr2(t_stack **a, t_stack **b, char **ins, int *i);
void	exec_instr(t_stack **stack_a, t_stack **stack_b, char **instr);
void	sa(t_stack **stack_a, t_bool bool);
void	sb(t_stack **stack_b, t_bool bool);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack_a, t_bool bool);
void	rb(t_stack **stack_b, t_bool bool);
void	rr(t_stack **stack_b, t_stack **stack_a);
void	rra(t_stack **stack_a, t_bool bool);
void	rrb(t_stack **stack_b, t_bool bool);
void	rrr(t_stack **stack_b, t_stack **stack_a);
#endif