/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:12:29 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/30 09:54:53 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dest < s)
		ft_memcpy(dest, s, len);
	i = len - 1;
	while (i >= 0 && dest > s)
	{
		*(dest + i) = *(s + i);
		i--;
	}
	return (dest);
}
