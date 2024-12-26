/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:45:24 by sdu               #+#    #+#             */
/*   Updated: 2024/12/18 12:28:08 by sdu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printhexa(long nb, char c)
{
	char	*base;
	char	*str;
	size_t	len;

	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	str = ft_itoa_base((unsigned int)nb, base);
	if (!str)
		return (0);
	len = ft_printstr(str);
	free(str);
	return (len);
}
