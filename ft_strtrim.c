/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:39:22 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/30 15:17:57 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	assign_str(char *str, char const *s1, size_t nb, size_t ne)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(s1) - (nb + ne)))
	{
		str[i] = s1[nb + i];
		i++;
	}
	str[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	nb;
	size_t	ne;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	nb = 0;
	ne = 0;
	while (s1[i] && in_check(s1[i++], set))
		nb++;
	i = ft_strlen(s1) - 1;
	while (nb < ft_strlen(s1) && i >= 0 && in_check(s1[i--], set))
		ne++;
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) - (nb + ne)) + 1));
	if (!str)
		return (NULL);
	assign_str(str, s1, nb, ne);
	return (str);
}
