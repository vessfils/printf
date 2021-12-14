/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/11 12:34:51 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifdef __APPLE__
#  define RETURN_NULL "0x0"
# else
#  define RETURN_NULL "(nil)"
# endif
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char*str, ...);
int		ft_printhexa(unsigned int nb, const char flag);
void	ft_puthexa(unsigned int nb, const char flag);
int		ft_hexalen(unsigned int nb);
int		ft_printchar(int c);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printpercentage(void);
int		ft_printnumber(int nb);
int		ft_printptr(unsigned long long nb);
void	ft_putchar(char c);
int		ft_printchar(int c);
int		ft_format(va_list args, const char flag);
int		ft_ptrlen(unsigned long long nb);
void	ft_putptr(unsigned long long nb);
int		ft_nbrlen(int nbr);
char	*ft_itoa(int nb);
int		ft_unbrlen(unsigned int nbr);
char	*ft_uitoa(unsigned int nb);
int		ft_printunsigned(unsigned int nb);
int		ft_strcmp(const char *s1, const char *s2);

#endif
