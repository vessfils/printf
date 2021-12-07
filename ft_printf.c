/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:42:05 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/07 23:32:31 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int ft_printpercentage (void)
{
	write(1, "%", 1);
	return (1);
}
int	ft_format(va_list args,  const char flag)
{
	int	size;
	int i;
	size = 0;
	if (flag == 'c')
		size += ft_printchar(va_arg (args, int));
	else if (flag == 's')
		size += ft_printstr(va_arg (args, char*));
	else if (flag == '%')
		size += ft_printpercentage();
	
	return (size);
}

int	ft_printf(const char*str, ...)
{
	va_list	args;
	int		i;
	int		size;

	size = 0;
	i = 0;
	va_start (args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = size + ft_format(args, str[i + 1]);
			i++;
		}
		else
			size = size +  ft_printchar(str[i]);
			i++;
	}
	va_end(args);
	return (size);
}

int main ()
{
	char a = 'c';
	char *b = "Hello World";

	ft_printf("%c", a);
	printf("\n");
	ft_printf("%s", b);
	printf("\n");
	ft_printf("%%\n");
	printf("\n");
	return(0);
}

