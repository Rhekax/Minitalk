/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:13:03 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/14 14:32:31 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	size_t			i;

	i = 0;
	dst_ptr = (unsigned char *) dst;
	if (len == 0 || src == dst)
		return (dst);
	if (src < dst)
	{
		while (len)
		{
			dst_ptr[len - 1] = ((const unsigned char *)src)[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		*dst_ptr = ((const unsigned char *)src)[i];
		i++;
		dst_ptr++;
	}
	return (dst);
}
