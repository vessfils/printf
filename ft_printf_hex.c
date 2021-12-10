/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/10 15:17:35 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexa(unsigned int nb, const char flag)
{
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, flag);
		ft_puthexa(nb % 16, flag);
	}
	else
	{
		if (flag == 'x')
			ft_putchar(base1[nb]);
		if (flag == 'X')
			ft_putchar(base2[nb]);
	}
}

int	ft_printhexa(unsigned int nb, const char flag)
{	
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(nb, flag);
	return (ft_hexalen(nb));
}
