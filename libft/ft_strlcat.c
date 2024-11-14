/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:12:55 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/08 18:59:13 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;

	i = 0;
	dstlen = 0;
	j = 0;
	while (*dst)
	{
		dst++;
		dstlen++;
	}
	while (src[i])
		i++;
	if (dstsize == 0 || dstsize <= dstlen)
		return (i + dstsize);
	while (src[j] && j < dstsize - dstlen - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = 0;
	return (dstlen + i);
}
