/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:47:39 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/20 13:26:31 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	ft_wdlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_remp(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	int		words;
	int		i;
	int		j;
	int		k;

	words = ft_cwords(s, c);
	big = (char **)malloc(sizeof(char *) * (words + 1));
	if (!big)
		return (NULL);
	ft_remp(&i, &j, &k);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		big[j] = (char *)malloc(sizeof(char) * (ft_wdlen(s, c, i) + 1));
		if (!big[j])
			return (NULL);
		while (s[i] != c && s[i])
			big[j][k++] = s[i++];
		big[j][k] = '\0';
		k = 0;
		j++;
	}
	return (big[j] = 0, big);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char **test = ft_split("test, test1, test2", ',');
	int	i = 0;
	while (i <= 2)
	{
		printf("%s\n", test[i]);
		free(test[i]);
		i++;
	}
	free(test);
}*/