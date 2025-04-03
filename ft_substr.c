/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:36:19 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/03 15:36:21 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	len_src = 0;
	while (src[len_src])
		len_src++;
	if (dstsize == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

char	*ft_substr(const char *src, size_t start, size_t len)
{
	size_t	len_src;
	char	*result;

	if (src == NULL)
		return (NULL);
	len_src = ft_strlen(src);
	if (start >= len_src)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (start + len > len_src)
		len = len_src - start;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, src + start, len + 1);
	return (result);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ptr;
	size_t	len_src;

	len_src = ft_strlen(src);
	ptr = (char *)malloc(len_src + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**add_string_to_array(char **array, char *str)
{
	int		count;
	char	**new_array;
	int		i;

	count = 0;
	while (array && array[count])
		count++;
	new_array = (char **)malloc(sizeof(char *) * (count + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = ft_strdup(str);
	if (!new_array[i])
	{
		free(new_array);
		return (NULL);
	}
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}
