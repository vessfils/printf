/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/10 11:44:11 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int nbr)
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

char	*ft_itoa(int nb)
{
	char		*str;
	long int	nbr;
	int			i;

	i = 0;
	str = 0;
	nbr = nb;
	str = (char *)malloc(sizeof(char) * ft_nbrlen(nb) + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	if (nbr < 0)
		nbr = -nbr;
	str[ft_nbrlen(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_nbrlen(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_nbrlen(nb) - i++] = (nbr % 10) + 48;
	return (str);
}

int	ft_printnumber(int nb)
{
	char	*str;

	str = ft_itoa(nb);
	ft_putstr(str);
	free(str);
	return (ft_nbrlen(nb));
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
