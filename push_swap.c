/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:58:30 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:08:28 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sorted.h"

void	ft_error(t_list **stk)
{
	ft_lstclear(stk);
	write (1, "error", 5);
	exit (-1);
}

int	check_dup_sort(t_list	**stk)
{
	t_list		*node;
	t_list		*nod;
	int			val[2];

	nod = *stk;
	val[1] = -33;
	while (nod)
	{
		val[0] = nod->val;
		node = nod->next;
		while (node)
		{
			if (val[0] == node->val)
				ft_error(stk);
			if (val[0] > node->val)
				val[1] = nod->x_sort++;
			else
				++(node->x_sort);
			node = node->next;
		}
		nod = nod->next;
	}
	return (val[1]);
}

void	algo_sorted(int count_val, t_list **stk_a)
{
	t_list	**stk_b;

	stk_b = (t_list **)malloc(sizeof(stk_b));
	if (!stk_b)
		return ;
	*stk_b = NULL;
	call_inst_(count_val, stk_a, stk_b);
	ft_lstclear(stk_b);
}

t_list	**great_list(int count, char **stk)
{
	t_list		**lst;

	if (count <= 1)
	{
		write (1, "error", 5);
		exit (-1);
	}
	lst = (t_list **)malloc(sizeof(lst));
	if (!lst)
		exit (-1);
	*lst = NULL;
	if (count == 2)
	{
		stk = ft_split(stk[1], ' ', &count);
		while (count-- > 0)
		{
			ft_lstadd_front(lst, ft_lstnew(ft_atoi(lst, stk[count])));
			free(stk[count]);
		}
		free (stk);
	}
	while (--count > 0)
		ft_lstadd_front(lst, ft_lstnew(ft_atoi(lst, stk[count])));
	return (lst);
}

int	main(int count, char **stk)
{
	t_list	**stack_a;

	stack_a = great_list(count, stk);
	if (check_dup_sort(stack_a) != -33)
		algo_sorted(ft_lstsize(*stack_a), stack_a);
	ft_lstclear(stack_a);
	return (0);
}
