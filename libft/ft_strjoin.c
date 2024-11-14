/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:02:01 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/10 16:35:06 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	ptrlen;
	int		i;

	i = 0;
	ptrlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *) malloc (sizeof(char) * ptrlen);
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		ptr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
