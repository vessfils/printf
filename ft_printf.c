/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:42:05 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/07 20:17:38 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}
int ft_printpercentage (char c)
{
	write(1, "%", 1);
	return (1);
}
int	ft_format(va_list args, const char*str)
{
	int	size;
	int	i;

	size = 0;
	if (str[i] == 'c')
		size += ft_printchar(va_arg (args, int));
	else if (str[i] == 's')
		size += ft_printstr(va_arg (args, char *));
	//else if (str[i] == '%')
	//	size += ft_printpercentage(va_arg (args, char));
	return (size);
}

int	ft_printf(const char*str, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start (args, str);
	size = 0;
	i = -1;
	if (!str)
		return (-1);
	while (str[--i])
	{
		if (str[i] == '%')
			size += ft_format(args, str + i + 1);
		else
			size += ft_printchar(str[i]);
	}
	va_end(args);
	return (size);
}

int main ()
{
	char a = '%';

//	ft_printf("%%");
	printf("%%");

	return(0);
}

