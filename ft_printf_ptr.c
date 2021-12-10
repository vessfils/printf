/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/10 16:45:49 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long nb)
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

void	ft_putptr(unsigned long long nb)
{
	char	*basex;

	basex = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		ft_putchar(basex[nb]);
	}
}

int	ft_printptr(unsigned long long int nb)
{
	if (nb == 0)
	{
		ft_putstr(RETURN_NULL);
		return (5);
	}	
	ft_putstr("0x");
	ft_putptr(nb);
	return(ft_ptrlen(nb) + 2);
}
