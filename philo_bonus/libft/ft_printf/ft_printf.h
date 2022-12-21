/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:16:18 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:16:18 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <unistd.h>
# include <stdarg.h>
# define BASE_FORMAT "cspdiuxX%%"
# define FLAGS "-0.# +"

int		ft_putchar(char c);
int		ft_putnbr_uns(unsigned int nbr, int *count);
int		ft_putnbr_base_hex(unsigned int nbr, int transform, int *count);
int		ft_putnbr(long int n, int *count);
int		ft_putstr_fd(char *s, int fd);
int		valid_format(const char *format);
size_t	ft_strlen(const char *s);
int		ft_valid(const char *base, char c);
int		ft_write_hex_adress(unsigned long int nbr, int *count);
int		ft_print_no_format(int c);
int		ft_isdigit(int c);
int		ft_isspace(const char c);
int		ft_print_zero(const char *format, va_list args_infos, size_t *i);
int		ft_print_char(int len, int c);
int		ft_print_plus(const char *format, va_list args_infos, size_t *i);
int		ft_print_hash(const char *format, va_list args_infos, size_t *i);
int		ft_print_space(const char *format, va_list args_infos, size_t *i);
int		ft_print_minus(const char *format, va_list args_infos, size_t *i);
int		ft_printf(const char *format, ...);

#endif