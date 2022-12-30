/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:59:56 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/28 18:11:18 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle && len != 0)
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (needle[j] == haystack[i + j])
			{
				if (needle[j + 1] == '\0')
					return ((char *)(haystack + i));
				j++;
			}
			i += j;
			i++;
		}
		return (0);
	}
	return ((char *)(haystack));
}
