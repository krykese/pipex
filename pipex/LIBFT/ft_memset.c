/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:14:11 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/13 22:57:03 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	if (!s)
	{
		return (NULL);
	}		
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
/*#include <stdio.h>
int main()
{
	    char str[70] = "mettre des points dans cette string a partir de str + 20.";
	        printf("\nBefore ft_memset(): %s\n", str);
		  
		    // Fill 2 characters starting from str[20] with '.'
		         ft_memset(str+20, '.', 2);       
		               printf("After ft_memset():  %s", str);
		                   return 0;            
}*/