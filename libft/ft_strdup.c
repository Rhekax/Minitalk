/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:16:19 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/09 18:30:34 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	length;
	int		i;

	i = 0;
	length = ft_strlen(s1) + 1;
	ptr = (char *) malloc (sizeof(char) * length);
	if (!ptr)
		return (NULL);
	while (length)
	{
		ptr[i] = s1[i];
		i++;
		length--;
	}
	return (ptr);
}
