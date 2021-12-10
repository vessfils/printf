/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:09:37 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/10 11:12:18 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char*str, ...);
int		ft_printhexa(unsigned int nb, const char flag);
void	ft_puthexa(unsigned int nb, const char flag);
int		ft_hexalen(int nb);
int		ft_printchar(int c);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printpercentage(void);
int		ft_printnumber(int nb);
int		ft_printptr(unsigned long long int nb);
void	ft_putchar(char c);
int		ft_printchar(int c);
int		ft_format(va_list args, const char flag);
int		ft_ptrlen(unsigned long long int nb);
void	ft_putptr(unsigned long long int nb);
int		ft_nbrlen(int nbr);
char	*ft_itoa(int nb);
int		ft_unbrlen(unsigned int nbr);
char	*ft_uitoa(unsigned int nb);
int		ft_printunsigned(unsigned int nb);

#endif
