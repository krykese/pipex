/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:17:19 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/20 20:21:23 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_str;

	if (nmemb && ((nmemb * size / nmemb) != size))
		return (NULL);
	new_str = malloc(nmemb * size);
	if (!new_str)
		return (NULL);
	ft_bzero((char *)new_str, nmemb * size);
	return ((char *)new_str);
}
