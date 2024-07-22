/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:57 by smonte-e          #+#    #+#             */
/*   Updated: 2022/12/02 15:46:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_included(char c1, const char	*set)
{
	while (*set)
	{
		if (c1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dst;
	size_t		start;
	size_t		end;
	size_t		len;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set || !*s1)
		return (ft_strdup(s1));
	while (is_included(s1[start], set) && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	if (start > end)
		return (ft_strdup(""));
	while (is_included(s1[end], set) && end > start)
		end--;
	len = end - start + 1;
	dst = ft_substr(s1, start, len);
	if (!dst)
		return (NULL);
	return (dst);
}
