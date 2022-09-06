/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:56:47 by gponcele          #+#    #+#             */
/*   Updated: 2022/08/01 15:01:23 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//# define LONG_MIN -9223372036854775808
//# define LONG_MAX +9223372036854775807

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//ft_printf.c
int						ft_printf(const char *s, ...);
int						ft_check_formats(char c, char *set);
int						ft_formats(va_list ap, const char format);
//ft_print_chars.c
int						ft_print_str(char *str);
int						ft_print_char(char c);
int						ft_print_percent(void);
int						ft_strlen_int(int n);
char					*ft_itoa(int n);
//ft_print_nbr.c
int						ft_print_nbr(int nb);
int						ft_strlen_int_unsigned(unsigned int n);
char					*ft_itoa_unsigned(unsigned int n);
int						ft_print_unsigned(unsigned int nb);
int						ft_print_hex(unsigned int n, const char format);
//ft_print_others.c
int						ft_print_ptr(unsigned long ptr);
int						ft_get_hex_ptr_len(unsigned long n);
char					*ft_get_hex(unsigned int num,
							const char format, unsigned int len);
char					*ft_get_ptr(unsigned long num, unsigned int len);

#endif