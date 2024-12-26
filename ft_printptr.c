/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:42:57 by sdu               #+#    #+#             */
/*   Updated: 2024/12/18 12:19:36 by sdu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printptr(long nb)
{
	char	*str;
	char	*base;
	size_t	len;

	base = "0123456789abcdef";
	if (nb == 0)
	{
		ft_printstr("(nil)");
		return (5);
	}
	ft_printstr("0x");
	str = ft_itoa_ptr((unsigned long long)nb, base);
	if (!str)
		return (0);
	len = (ft_printstr(str) + 2);
	free(str);
	return (len);
}

static size_t	ft_count_base(unsigned long long n, char *base)
{
	size_t				i;
	unsigned long long	len_base;

	i = 1;
	len_base = ft_strlen(base);
	while (n > len_base - 1)
	{
		n = n / len_base;
		i++;
	}
	return (i);
}

char	*ft_itoa_ptr(unsigned long long n, char *base)
{
	char	*str;
	size_t	i;

	i = ft_count_base(n, base);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (n > (unsigned long long)ft_strlen(base) - 1)
	{
		str[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i--;
	}
	str[i] = base[n % ft_strlen(base)];
	return (str);
}
