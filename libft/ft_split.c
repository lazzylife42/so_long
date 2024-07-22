/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:10:33 by smonte-e          #+#    #+#             */
/*   Updated: 2022/12/13 15:47:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_arr(char **tab)
{
	int	i;

	i = 0;
	while ((char *)tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (NULL);
}

static int	word_numb(const char *str, char c)
{
	char	last;
	int		i;
	int		w_count;

	last = c;
	i = 0;
	w_count = 0;
	while (str[i] != '\0')
	{
		if (last == c && str[i] != c)
			w_count++;
		last = str[i];
		i++;
	}
	return (w_count);
}

static char	*word_dup(const char *str, size_t start, size_t end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = (char)str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		w_start;

	split = (char **)malloc((word_numb(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = -1;
	j = 0;
	w_start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && w_start < 0)
			w_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && w_start >= 0)
		{
			split[j] = word_dup(s, w_start, i);
			if (!(split[j++]))
				return (free_arr(split));
			w_start = -1;
		}	
	}
	split[j] = NULL;
	return (split);
}
