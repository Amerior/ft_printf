/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:12:53 by sdu               #+#    #+#             */
/*   Updated: 2024/12/18 13:05:54 by sdu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_format(const char format, va_list va)
{
	if (format == 'c')
		return (ft_printchar(va_arg(va, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(va, char *)));
	else if (format == 'p')
		return (ft_printptr(va_arg(va, unsigned long long)));
	else if (format == 'i' || format == 'd' || format == 'u')
		return (ft_print_base10(va_arg(va, long), format));
	else if (format == 'x' || format == 'X')
		return (ft_printhexa(va_arg(va, unsigned int), format));
	else if (format == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		count;
	int		i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += printf_format(str[i], va);
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(va);
	return (count);
}
