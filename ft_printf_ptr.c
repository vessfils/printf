/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/11 12:33:15 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
		if (!ft_strcmp(RETURN_NULL, (char *)"(nil)"))
			return (5);
		if (!ft_strcmp(RETURN_NULL, (char *)"0x0"))
			return (3);
	}
	ft_putstr("0x");
	ft_putptr(nb);
	return (ft_ptrlen(nb) + 2);
}
