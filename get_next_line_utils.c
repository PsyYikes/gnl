/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia <fgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:27:45 by fgarcia           #+#    #+#             */
/*   Updated: 2024/01/23 15:04:53 by fgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		j;
	int		i;

	i = 0;
	j = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[(i + j)] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (str);
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (str + i - 1);
		if (str[i] == '\0')
			return (str);
		i++;
	}
	return (str + i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			resultat;
	size_t			i;
	unsigned char	*ret;

	resultat = nmemb * size;
	ret = malloc(resultat);
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	i = 0;
	while (i < resultat)
	{
		*(unsigned char *)(ret + i) = 0;
		i++;
	}
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		j;

	if (!src)
		return (NULL);
	j = 0;
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
