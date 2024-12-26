/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:33:44 by sdu               #+#    #+#             */
/*   Updated: 2024/12/18 17:05:36 by sdu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	if (!str)
	{
		ft_printstr("(null)");
		return (6);
	}
	return (i);
}

static size_t	ft_count_base(long long n, char *base)
{
	size_t		i;
	long long	len_base;

	i = 1;
	len_base = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > len_base - 1)
	{
		n = n / len_base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long n, char *base)
{
	char	*str;
	size_t	i;

	i = ft_count_base(n, base);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = base[0];
	while (n > ft_strlen(base) - 1)
	{
		str[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i--;
	}
	str[i] = base[n % ft_strlen(base)];
	return (str);
}
