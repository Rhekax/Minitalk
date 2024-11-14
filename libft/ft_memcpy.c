/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:13:05 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/09 15:04:05 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*ptr;
	char		*dstptr;

	dstptr = (char *) dst;
	ptr = (const char *) src;
	if (dst == src)
		return (dst);
	while (n)
	{
		*dstptr = *ptr;
		ptr++;
		dstptr++;
		n--;
	}
	return (dst);
}
