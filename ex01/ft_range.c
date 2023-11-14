/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:16:39 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/11 18:16:42 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	*ptr;
	int	i;

	ptr = 0;
	i = 0;
	if (min >= max)
		return (ptr);
	tab = (int *)malloc(4 * (max - min));
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

/* int	main(void)
{
	int	*tab;
	int	i;

	tab = ft_range(-10, 10);
	i = 0;

	while (i < 19)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	printf("%d\n", tab[i]);
	return (0);
} */