/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:03:52 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/19 16:31:03 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (destination > source)
	{
		i = n;
		while (i-- > 0)
		{
			destination[i] = source[i];
		}
	}
	else
	{
		ft_memcpy(destination, source, n);
	}
	return (dest);
}

/*#include <stdio.h>
int main () 
{
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
   
   
   ft_memcpy(destination, source, i);


}*/