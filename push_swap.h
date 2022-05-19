/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:09:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 18:02:18 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(t_stack **stack, int value);
void	stack_clear(t_stack **stack);
void	stack_swap(t_stack **stack);
void	stack_push(t_stack **dest, t_stack **src);
void	stack_rotate(t_stack **stack);
void	stack_reverse_rotate(t_stack **stack);

int		args_to_stack(int argc, char *argv[], t_stack **stack);
int		put_error(void);

void	show_state(t_stack *stack_a, t_stack *stacl_b);

void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sorted_insert(t_stack **stack_a, t_stack **stack_b);
#endif
