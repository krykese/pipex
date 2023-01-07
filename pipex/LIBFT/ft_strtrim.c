/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:15 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/20 10:58:22 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		k;
	char	*s2;

	i = 0;
	while (s1[i] != '\0' && ft_is_in(set, s1[i]) == 1)
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_is_in(set, s1[j - 1]) == 1)
		j--;
	s2 = (char *)malloc (sizeof(*s1) * ((j - i) + 1));
	if (!s2)
		return (NULL);
	k = 0;
	while (i < j)
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	s2[k] = '\0';
	return ((char *)s2);
}

/*#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char s1[] = "Bonjour ca va jourBon";
	const char set[] = "jour";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/