/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:47:19 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/30 15:52:54 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chtostr(char c)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	i = 0;
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

static int	nofstrings(char *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			n++;
		i++;
	}
	return (n + 1);
}

static void	freestr(char **str, int i)
{
	while (i > 0)
	{
		free(str[i]);
		str[i] = NULL;
		i--;
	}
}

static char	**assign_strs(char **str, char *chr, char c, int i)
{
	int	j;
	int	k;

	k = -1;
	while (chr[++k])
	{
		j = -1;
		while (chr[k + ++j] != c && chr[k + j])
		{
			if (chr[k + j + 1] == c || !chr[k + j + 1])
			{
				str[i] = (char *)malloc(sizeof(char) * (j + 2));
				if (str[i] == NULL)
				{
					freestr(str, --i);
					return (NULL);
				}
				ft_strlcpy(str[i++], chr + k, j + 2);
				k += j;
				j = 0;
			}
		}
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*chr;
	int		i;

	if (!s)
		return (NULL);
	chr = ft_strtrim(s, chtostr(c));
	if (!chr)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (nofstrings(chr, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	str = assign_strs(str, chr, c, i);
	return (str);
}
