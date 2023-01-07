/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:35:56 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/20 16:03:07 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*new_str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			new_str[j++] = s[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

/*#include <stdio.h>
int	main()
{
	//char	*str = "BONJOUR TOUT LE MONDE";
	
	printf("%p\n", ft_substr(NULL, 30, 21));
	return (0);
	
}*/