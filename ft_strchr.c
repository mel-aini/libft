/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:15:05 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/30 15:52:18 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(s) + 1;
	i = 0;
	while (i < n)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
