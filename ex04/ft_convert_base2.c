/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:16 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/13 11:12:20 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		s_b_w(char *base_to, int mode);
void	initialize_params(int *lentoprint, unsigned int *nbr_u);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

int	ft_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result = result * base;
		exp--;
	}
	return (result);
}

int	is_from_the_base(char c, char *base, int mode)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
		{
			if (mode == 1)
				return (i);
			else if (mode == 2)
				count++;
			else
				return (1);
		}
		i++;
	}
	if (mode == 2)
		return (count);
	else
		return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				nb;
	unsigned int	count;

	i = 0;
	initialize_params(&nb, &count);
	if (s_b_w(base, 3) == 3)
		return (0);
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			count++;
			i++;
		}
		else if (is_from_the_base(str[i], base, 0))
			nb = nb * ft_strlen(base) + (is_from_the_base(str[i++], base, 1));
		else
			break ;
	}
	return (ft_pow(-1, (int) count) * nb);
}
