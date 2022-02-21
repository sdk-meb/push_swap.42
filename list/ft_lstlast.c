/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:42:50 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/10 10:10:20 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../sorted.h"
//last node in list

t_list	*ft_lstlast(t_list **lst)
{
	t_list	*p;

	if (!lst)
		return (NULL);
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	return (p);
}
