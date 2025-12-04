/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:01:58 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/05 13:01:59 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_stackab
{
	t_stack	a;
	t_stack	b;
	int		size;
}	t_stackab;

int		*format_list(t_stackab *s, int argc, char **argv);
int		do_op(t_stackab *stack, char *c);
int		ft_swap(t_stack *stack, int size);
int		ft_push(t_stack *stack1, t_stack *stack2);
int		ft_rotate(t_stack *stack, int size);
int		ft_reverse_rotate(t_stack *stack, int size);
void	two_sort(t_stackab *s);
void	three_sort(t_stackab *s);
void	small_sort(t_stackab *s);
void	big_sort(t_stackab *stackab);
void	view_stack(t_stackab s);
int		get_list_size(int argc, char **argv);
int		check_args(char **argv, int size);
void	check_values(int size, int *list);

#endif
