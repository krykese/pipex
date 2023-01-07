/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:44:48 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/19 16:31:32 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;
	long int	nbr;

	nbr = n;
	len = ft_get_len(n);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		dest[0] = '-';
	}
	while (nbr >= 10)
	{
		dest[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	dest[len--] = nbr + '0';
	return (dest);
}

/*#include <stdio.h>
int	main()
{
	int	n;
	n = -148521;
	printf("%s\n",ft_itoa(n));
	return (0);
}*/
