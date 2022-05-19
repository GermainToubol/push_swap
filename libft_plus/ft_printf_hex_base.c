/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:55:30 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/16 16:53:40 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

static int	get_hex_len(unsigned int nbr);
static void	putnbr_hex(unsigned int nbr, char *charset);

int	ft_printf_hex_base(unsigned int nbr, char *charset, t_convert *convert)
{
	int	len;

	len = get_hex_len(nbr);
	len += ft_len_precision(len, convert);
	if (nbr != 0 && convert->alternate == '#')
	{
		if (!convert->leftify && convert->padd_char == ' ')
			len += ft_printf_padding(len + 2, convert);
		len += write(1, charset + 16, 2);
		if (!convert->leftify && convert->padd_char == '0')
			len += ft_printf_padding(len, convert);
	}
	else
	{
		if (!convert->leftify)
			len += ft_printf_padding(len, convert);
	}
	ft_printf_precision(convert);
	putnbr_hex(nbr, charset);
	len += ft_printf_padding(len, convert);
	return (len);
}

static int	get_hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static void	putnbr_hex(unsigned int nbr, char *charset)
{
	if (nbr == 0)
		return ;
	if (nbr > 15)
		putnbr_hex(nbr / 16, charset);
	ft_putchar_fd(charset[nbr % 16], 1);
}
