/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:37:13 by cyetta            #+#    #+#             */
/*   Updated: 2024/02/15 20:26:38 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../inc/libft.h"

/*
Creates a duplicate (with malloc) of string s1 and returns a pointer to it.
*/
char *ft_strdup(const char *s1)
{
	size_t len;
	char *dst;

	len = ft_strlen(s1);
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (dst)
	{
		ft_memcpy(dst, s1, len);
		dst[len] = '\0';
	}
	return (dst);
}
