/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:58:14 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/20 16:34:45 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	i = 0;
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
