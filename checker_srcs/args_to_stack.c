/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:54:13 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 10:22:51 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static void	stack_transfer(t_stack **dest, t_stack **src);
static int	nbr_cmp(char *str1, char *str2);
static int	is_in_stack(int n, t_stack *stack);

int	args_to_stack(int argc, char *argv[], t_stack **stack)
{
	t_stack	*tmp_stack;
	int		i;
	int		value;
	char	*tmp;

	tmp_stack = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		tmp = ft_itoa(value);
		if (tmp == NULL || nbr_cmp(tmp, argv[i])
			|| is_in_stack(value, tmp_stack))
		{
			free(tmp);
			stack_clear(&tmp_stack);
			return (-1);
		}
		free(tmp);
		stack_new(&tmp_stack, value);
		i++;
	}
	stack_transfer(stack, &tmp_stack);
	return (0);
}

static void	stack_transfer(t_stack **dest, t_stack **src)
{
	while (*src)
	{
		stack_push(dest, src, NULL);
	}
}

static int	nbr_cmp(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str2[j] == '+')
		j++;
	while (str1[i] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	while (str1[i] == '0')
		i++;
	while (str2[j] == '0')
		j++;
	while (str1[i] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	return (str1[i] - str2[j]);
}

static int	is_in_stack(int n, t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
