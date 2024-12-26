/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:22:28 by sdu               #+#    #+#             */
/*   Updated: 2024/12/18 14:27:04 by sdu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(const char *str);
int		ft_strlen(const char *str);
size_t	ft_printhexa(long nb, char c);
size_t	ft_printptr(long nb);
size_t	ft_print_base10(long nb, char c);
char	*ft_itoa_base(long long n, char *base);
char	*ft_itoa_ptr(unsigned long long n, char *base);

#endif
