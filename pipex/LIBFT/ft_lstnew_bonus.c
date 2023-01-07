/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:40:44 by qcosta            #+#    #+#             */
/*   Updated: 2022/05/20 19:27:14 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/*#include <stdio.h>

void print(t_list *list)
{
	t_list *tmp = list;	
	
	printf("\n-----------------\n\n");
	while (tmp->next)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf(" dernier element %s\n", (char *)tmp->content);
	printf("\n-----------------\n\n");
}
int main(void)
{
	t_list *list;
	int	i;

	list = ft_lstnew((char *){"str"});
	printf("%s\n", (char *)list->content);
	printf("\n-----------------\n\n");

	i = 0; 
	while(i < 4) 
	{
		t_list *l = ft_lstnew((char *){"42"});
		ft_lstadd_back(&list, l);
		i++;
	}
	print(list);
	t_list *l = ft_lstnew((char *){"43"});
	ft_lstadd_front(&list, l);
	l = ft_lstnew((char *){"44"});
	ft_lstadd_back(&list, l);
	print(list);
	printf("===========================\n");
	printf("Size: %d\n", ft_lstsize(list));
	printf("Last: %s\n", (char *)ft_lstlast(list)->content);
	ft_lstlast(list)->next =  ft_lstnew((char *){"45"});
	printf("Size: %d\n", ft_lstsize(list));

	printf("Last: %s\n", (char *)ft_lstlast(list)->content);
	printf("\n-------------------\n\n");
}*/