/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:54:13 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 15:12:31 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	stack_transfer(t_stack **dest, t_stack **src);

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
		if (tmp == NULL || ft_strncmp(tmp, argv[i], ft_strlen(argv[i])))
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
		stack_push(dest, src);
	}
}
