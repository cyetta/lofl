/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:23:37 by cyetta            #+#    #+#             */
/*   Updated: 2024/02/15 20:26:14 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = malloc(count * size);
	if (m)
		ft_bzero(m, count * size);
	return (m);
}
