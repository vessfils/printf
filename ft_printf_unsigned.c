/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/10 14:53:32 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrlen(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int nb)
{
	char		*str;
	long int	nbr;
	int			i;

	i = 0;
	str = 0;
	nbr = nb;
	str = (char *)malloc(sizeof(char) * ft_unbrlen(nb) + 1);
	if (!str)
		return (NULL);
	str[ft_unbrlen(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_unbrlen(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_unbrlen(nb) - i++] = (nbr % 10) + 48;
	return (str);
}

int	ft_printunsigned(unsigned int nb)
{
	char	*str;
	
	if (nb == 0)
		write(1, "0", 1);
	else
	{
		str = ft_uitoa(nb);
		ft_putstr(str);
		free(str);
	}
	return (ft_unbrlen (nb));
}
