/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:48:32 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/10 14:31:23 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return (((char *) haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[j + i] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return (&((char *) haystack)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
