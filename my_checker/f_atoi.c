/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:26:22 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/10 14:36:28 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (!src && !dst)
		return (NULL);
	s = src;
	d = dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int	ft_atoi(t_list **lstclr, char *str)
{
	int		i;
	long	n;
	int		s;	

	i = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
		s = 44 - str[i++];
	if (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i] - 48);
		while (i++, str[i] >= '0' && str[i] <= '9')
			n = (str[i] - 48) + (10 * n);
		n = n * s;
	}
	if (str[i] || (n > 2147483647 || n < -2147483648))
	{
		ft_lstclear(lstclr);
		write (1, "error", 5);
		exit (-1);
	}
	return (n);
}