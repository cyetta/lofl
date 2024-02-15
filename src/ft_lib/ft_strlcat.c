/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:37:32 by cyetta            #+#    #+#             */
/*   Updated: 2024/02/15 20:31:22 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../inc/libft.h"

/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(src) + MIN(siz, strlen(initial dst)).
 * If retval >= siz, truncation occurred.
 */
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t src_sz;
	size_t dst_sz;
	size_t i;

	dst_sz = ft_strlen(dst);
	src_sz = ft_strlen(src);
	if (dst_sz > dstsize)
		return (src_sz + dstsize);
	i = 0;
	while ((i + dst_sz + 1) < dstsize && src[i])
	{
		dst[i + dst_sz] = src[i];
		i++;
	}
	dst[i + dst_sz] = 0;
	return (src_sz + dst_sz);
}
