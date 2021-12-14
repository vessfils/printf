/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:42:05 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/10 19:21:16 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printpercentage(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_format(va_list args, const char flag)
{
	int	size;

	size = 0;
	if (flag == 'c')
		size += ft_printchar(va_arg (args, int));
	else if (flag == 's')
		size += ft_printstr(va_arg (args, char *));
	else if (flag == '%')
		size += ft_printpercentage();
	else if (flag == 'x')
		size += ft_printhexa(va_arg (args, unsigned int), flag);
	else if (flag == 'X')
		size += ft_printhexa(va_arg (args, unsigned int), flag);
	else if (flag == 'i' || flag == 'd')
		size += ft_printnumber(va_arg (args, int));
	else if (flag == 'u')
		size += ft_printunsigned(va_arg (args, unsigned int));
	else if (flag == 'p')
		size += ft_printptr(va_arg (args, unsigned long long));
	return (size);
}

int	ft_printf(const char *str, ...)
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
			size = size + ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}

/*
int main ()
{
	char a = 'c';
	char *b = "Hello World";
	char *ptr = NULL;
	int nb = 42;

	printf("%p\n", ptr);
	ft_printf("%p", ptr);
	
	printf("%x\n", 16);
	ft_printf("%x", 16);
	ft_printf("%p", );
	ft_printf("%c", a);
	printf("\n");
	printf("%s\n", b);
	ft_printf("%s", b);
	printf("\n");
	printf("%%");
	ft_printf("%%\n");
	printf("\n");
	printf("%p\n", &a);
	ft_printf("%p", ptr);
	printf("\n");
	printf("%x\n", nb);
	ft_printf("%x\n", nb);
	printf("%s\n", "0");
	ft_printf("%s\n", "0"); 
	printf("%X\n", nb);
	ft_printf("%X\n", nb);
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);

	printf("%u\n", -1);

	ft_printf("%u", -1);

	return(0);
}
*/
