/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:22:06 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/11 17:22:28 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc(i + 1);
	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int main(void)
{
	char *src = "Hello World!";
	char *dest1;
	char *dest2;

	dest1 = ft_strdup(src);
	dest2 = strdup(src);
	src = "Adios Mundo!";
	printf("Propia\t\t%s\n", dest1);
	printf("Original\t%s\n", dest2);
	free(dest1);
	free(dest2);
	return (0);
} */