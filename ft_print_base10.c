/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:15:23 by sdu               #+#    #+#             */
/*   Updated: 2024/12/18 12:57:22 by sdu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_base10(long nb, char c)
{
	char	*str;
	char	*base;
	size_t	len;

	base = "0123456789";
	if (c == 'u')
		str = ft_itoa_base((unsigned int)nb, base);
	else
		str = ft_itoa_base((int)nb, base);
	if (!str)
		return (0);
	len = ft_printstr(str);
	free(str);
	return (len);
}
