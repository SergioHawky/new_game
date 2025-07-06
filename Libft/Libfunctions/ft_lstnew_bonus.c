/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:27:36 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/23 11:02:06 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	root->content = content;
	root->next = NULL;
	return (root);
}

/* int main ()
{
   t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *node5;


	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node4 = malloc(sizeof(t_list));

	node1->content = "1";
	node2->content = "2";
	node3->content = "3";
	node4->content = "4";
	node5 = ft_lstnew("5");

	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = node5;
	while(node1 != NULL)
	{
		printf("\n%s\n",  (char *)node1->content);
		node1 = node1->next;
	}
} */