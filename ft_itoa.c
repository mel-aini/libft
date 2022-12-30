/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:39:40 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/29 12:38:39 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static int	power(int b, int e)
{
	int	i;
	int	n;

	n = 1;
	if (e == 0)
		return (1);
	if (e == 1)
		return (b);
	i = 0;
	while (i < e)
	{
		n *= b;
		i++;
	}
	return (n);
}

static void	conv(char *str, int n, int x, int l)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
	}	
	while (i < l)
	{
		str[i] = (n / x) + '0';
		n %= x;
		x /= 10;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;
	int		x;

	l = len(n);
	x = power(10, l - 1);
	if (n < 0)
		x /= 10;
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	if (n != -2147483648)
	{
		conv(str, n, x, l);
		return (str);
	}
	ft_memcpy(str, "-2147483648", 11);
	return (str);
}
