/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:45:44 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/12 15:13:14 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	i = 0;
	if (!src && !dst)
		return (slen);
	if (!dstsize)
		return (slen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		start = slen;
	if (len > slen)
		len = slen - start;
	if (s[start] == 0)
		len = 0;
	if (start + len > slen)
		len = ft_strlen(s + start);
	sbstr = malloc((len + 1) * sizeof(char));
	if (!sbstr)
		return (0);
	ft_strlcpy(sbstr, s + start, len + 1);
	return (sbstr);
}
