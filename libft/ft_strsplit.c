/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:28:22 by madan             #+#    #+#             */
/*   Updated: 2019/09/16 18:16:15 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clear(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
	return (NULL);
}

static int	ft_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (k < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(str[k] = (char*)malloc(sizeof(char) * (ft_len(s + i, c) + 1))))
			return (ft_clear(str));
		str[k] = ft_strncpy(str[k], s + i, ft_len(s + i, c));
		str[k][ft_len(s + i, c)] = '\0';
		k++;
		while (s[i] && s[i] != c)
			i++;
	}
	str[k] = NULL;
	return (str);
}
