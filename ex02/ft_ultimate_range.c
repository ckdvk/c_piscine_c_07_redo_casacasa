/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:19:33 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/13 10:19:36 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(4 * (max - min));
	if (*range == NULL)
		return (-1);
	else
	{
		while (min < max)
		{
			(*range)[i] = min;
			count++;
			min++;
			i++;
		}
	}
	return (count);
}
/* 
int	main(void)
{
	int *range;
	int min;
	int max;
	int count;
	int i;

	min =-214;
	max = 215;
	
	// *range = 0;

	count = ft_ultimate_range(&range, min, max);
	printf("count: %d\n", count);
	if (min >= max)
	{
		printf("range: %d\n", *range);
		return (0);
	}
	i = 0;
	while (min < max)
	{
		printf("%d\n", range[i]);
		min++;
		i++;
	}
	return (0);
}
 */