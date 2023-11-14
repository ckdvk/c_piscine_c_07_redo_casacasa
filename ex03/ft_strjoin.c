/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:19:47 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/13 10:19:50 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	j;

	j = 0;
	while (*dest != '\0')
		dest++;
	while (src[j] != '\0')
	{
		*dest = src[j];
		dest++;
		j++;
	}
	*dest = '\0';
	dest++;
	return (dest);
}

char	*if_size_0(char *output)
{
	output = (char *)malloc(1);
	output[0] = '\0';
	return (output);
}

void	initialize(int *i, int *memcount)
{
	*i = 0;
	*memcount = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*output;
	int		memcount;

	initialize(&i, &memcount);
	if (size == 0)
		return (if_size_0(output));
	while (i < size)
		memcount = memcount + ft_strlen(strs[i++]) + ft_strlen(sep);
	output = (char *)malloc(memcount + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(output, strs[i]);
		if (i < size - 1)
			ft_strcat(output, sep);
		i++;
	}
	output[memcount] = '\0';
	return (output);
}

/* int main(int argc, char **argv)
{
	char *sep;
	int size;
	char *output;

	sep = argv[1];
	size = argc - 2;
	output =  ft_strjoin(size, argv + 2, sep);
	printf("%s\n", output);
	free(output);
	return (0);
}
 */