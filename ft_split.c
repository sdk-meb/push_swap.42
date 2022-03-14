/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:18:49 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:07:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sorted.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_words(const char *str, char c)
{
	int	i;	
	int	r;

	i = 0;
	r = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && r == 0)
		{
			r = 1;
			i++;
		}
		else if (*str == c)
			r = 0;
		str++;
	}
	return (i);
}

char	**ft_free(char **f)
{
	while (*f)
		free(*f++);
	free (f);
	return (NULL);
}

char	*ft_sub(const char *str, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len - start + 1) * sizeof(char));
	if (!word || !str)
	{
		free (word);
		return (NULL);
	}
	while (start < len)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c, int *count)
{
	t_intgr	spl;
	char	**h;

	if (!s)
		return (NULL);
	*count = (ft_words(s, c));
	h = malloc(*count * sizeof(char *));
	if (!h)
		return (NULL);
	spl.i = -1;
	spl.j = 0;
	spl.n = -1;
	while (++(spl.i) <= (int)ft_strlen(s))
	{
		if (s[spl.i] != c && spl.n < 0)
			spl.n = spl.i;
		else if ((s[spl.i] == c || spl.i == (int)ft_strlen(s)) && spl.n >= 0)
		{
			h[spl.j] = ft_sub(s, spl.n, spl.i);
			if (!h[spl.j++])
				return (ft_free(h));
			spl.n = -1;
		}
	}
	return (h);
}
