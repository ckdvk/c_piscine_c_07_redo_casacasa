/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:20:01 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/13 10:20:36 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_pow(int base, int exp);
int		is_from_the_base(char c, char *base, int mode);
int		which_from_the_base(char c, char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char	*str);

int	s_b_w(char *base_to, int mode)
{
	int	i;
	int	condition;

	condition = 0;
	i = 0;
	while (i < ft_strlen(base_to))
	{
		if (base_to[i] == ' ' || (base_to[i] >= 9 && base_to[i] <= 13))
			condition = 1;
		else if (base_to[i] == '+' || base_to[i] == '-')
			condition = 1;
		else if (is_from_the_base(base_to[i], base_to, 2) != 1)
		{
			condition = 1;
		}
		i++;
	}
	if (condition == 1)
	{
		return (mode);
	}
	else
		return (0);
}

void	m_u_p_b(unsigned int nbr_unsigned, char *base, char *output, int k)
{
	int				i;
	unsigned int	baselen;
	unsigned int	quo;
	unsigned int	mod;

	baselen = ft_strlen(base);
	i = 0;
	if (s_b_w(base, 4) == 4)
		return ;
	if (nbr_unsigned >= baselen)
	{
		quo = nbr_unsigned / baselen;
		mod = nbr_unsigned % baselen;
		m_u_p_b(mod, base, output, k);
		m_u_p_b(quo, base, output, k - 1);
	}
	else
	{
		output[k] = base[nbr_unsigned];
	}
}

void	initialize_params( int *lentoprint, unsigned int *nbr_u)
{
	*lentoprint = 0;
	*nbr_u = 0;
}

int	how_many_digits(unsigned int nbr_unsigned, int lenbaseto)
{
	int				lentoprint;
	unsigned int	nbr_unsigned_aux;

	lentoprint = 0;
	nbr_unsigned_aux = nbr_unsigned;
	while (nbr_unsigned_aux != 0)
	{
		nbr_unsigned_aux = nbr_unsigned_aux / lenbaseto;
		lentoprint++;
	}
	return (lentoprint);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				nb;
	char			*output;
	unsigned int	nbr_unsigned;
	int				lentoprint;

	output = malloc(100);
	initialize_params(&lentoprint, &nbr_unsigned);
	nb = ft_atoi_base(nbr, base_from);
	if (s_b_w(base_to, 2) == 2 || s_b_w(base_from, 3) == 3 || !output)
		return (NULL);
	if (nb < 0)
	{
		ft_strcpy(output, "-");
		lentoprint++;
		nbr_unsigned = (nb * -1);
	}
	else
		nbr_unsigned = nb;
	lentoprint = lentoprint + how_many_digits(nbr_unsigned, ft_strlen(base_to));
	if (nbr_unsigned == 0)
		lentoprint++;
	m_u_p_b(nbr_unsigned, base_to, output, lentoprint - 1);
	output[lentoprint] = '\0';
	return (output);
}

/* int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./a.out <number>\n");
        return(1);
    }
    char base_from[] = "asdfghjklz";
    char base_to[] = "01";
    char *res = ft_convert_base(argv[1], base_from, base_to);
    long int n = ft_atoi_base(argv[1], base_from);
    printf("\n\"%s\" en base (\"%s\") = %ld en base (\"0123456789\")\n",
    argv[1], base_from, n);
    printf("%ld en base (\"0123456789\") = %s en base (\"%s\")\n\n", n, res, base_to);
    free(res);
    return(0);
} */
int main() {
    char *numeros[] = {"101", "234", "1001", "1111", "3210", "ABCDEF", "XYZ", "0", "123456", "987654", "-101", "11", "1000000", "202020", "ABCD", "2147483647", "-2147483648", "-012334", "   123", "123 456"};
    char *bases_from[] = {"01", "01234567", "0123456789", "0123456789ABCDEF", "0123", "ABCDEF", "ABC", "01", "01234567", "0123456789ABCDEF", "01", "01", "01", "012", "0123456789ABCDEF", "0123456789", "01", " 0123456789", "0123456789", "0123456789"};
    char *bases_to[] = {"0123456789", "01", "0123456789ABCDEF", "0123456789", "0123456789", "0123456789", "01", "0123456789ABCDEF", "01", "0123456789", "0123456789ABCDEF", "0123456789ABCDEF", "0123456789", "01", "0123456789ABCDEF", "0123456789", "0123456789ABCDEF", "01", "01", "01"};

    printf("Pruebas de conversión de bases con casos raros:\n\n");

    for (int i = 0; i < 20; i++) {
        char *resultado = ft_convert_base(numeros[i], bases_from[i], bases_to[i]);

        printf("Prueba %d:\n", i + 1);
        if (resultado != NULL) {
            printf("Número original: %s en base %s\n", numeros[i], bases_from[i]);
            printf("Convertido a base %s: %s\n", bases_to[i], resultado);
            free(resultado); // Liberar la memoria asignada
        } else {
            printf("Error en la conversión.\n");
        }
        printf("\n");
    }

    return 0;
}