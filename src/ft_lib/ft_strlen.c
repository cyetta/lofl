/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:15:33 by cyetta            #+#    #+#             */
/*   Updated: 2024/02/15 20:14:06 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Returns length of string s
*/
size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
		++len;
	return (len);
}
