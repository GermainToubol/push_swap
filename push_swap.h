/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:09:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 12:27:27 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	char			name;
	struct s_stack	*next;
}	t_stack;

typedef struct s_inst
{
	int				exec;
	struct s_inst	*next;
	struct s_inst	*previous;
}	t_inst;

t_stack	*stack_new(t_stack **stack, int value);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		stack_n_sorted(t_stack *stack, int size, int grow);

void	stack_swap(t_stack **stack, t_inst **instruct);
void	stack_push(t_stack **dest, t_stack **src, t_inst **instruct);
void	stack_rotate(t_stack **stack, t_inst **instruct);
void	stack_reverse_rotate(t_stack **stack, t_inst **instruct);

int		args_to_stack(int argc, char *argv[], t_stack **stack);
int		put_error(void);

void	show_state(t_stack *stack_a, t_stack *stacl_b);

void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sorted_insert(t_stack **stack_a, t_stack **stack_b);

void	divide(t_stack **stack_a, t_stack **stack_b, int size,
			t_inst **instruct);
void	merge(t_stack **stack_a, t_stack **stack_b, int size,
			t_inst **instruct);

void	clean_instructions(t_inst **instructions);
int		new_instr(t_inst **instruct, int exec);
void	printf_free_instr(t_inst *instr);

int		is_top_ordered(t_stack *stack, int grow);
int		inter_mid(t_stack *stack, int size);
void	int_sort(int *value, int size);
int		median(t_stack *stack, int size);
#endif
