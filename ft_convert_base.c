/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:28:49 by jainavas          #+#    #+#             */
/*   Updated: 2024/09/27 18:40:15 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

unsigned long	reducelines(char *str, int i, unsigned long res, char *base)
{
	int	j;

	while (str[i] != '\0')
	{
		j = 0;
		while (j < (int)ft_strlen(base))
		{
			if (str[i] == base[j])
			{
				res *= (int)ft_strlen(base);
				res += j;
				break ;
			}
			j++;
		}
		if (j == (int)ft_strlen(base))
			break ;
		i++;
	}
	return (res);
}

int	debugbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	if ((int)ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-') || (base[i] == ' '))
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned long	ft_atoi_base(char *str, char *base)
{
	int				i;
	unsigned long	res;
	int				sign;

	if (!debugbase(base))
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	res = reducelines(str, i, res, base);
	return (sign * res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned long	atoi;

	if (!(debugbase(base_from) && debugbase(base_to)))
		return ((void *)0);
	atoi = ft_atoi_base(nbr, base_from);
	free(nbr);
	return (ft_putnbr_base(atoi, base_to));
}

// int main()
// {
//     char base1[] = "0123456789ABCDEF"; // Base hexadecimal
//     char str1[] = " ------+++++--FF1A3";
//     char base2[] = "01";              // Base binaria
//     char str2[] = " -+----------+1101";
//     char base3[] = "0123456789";           // Base personalizada
//     char str3[] = "       -++++-552";

// printf(" %s base %s: %s\n", str1, 
// base1, ft_convert_base(str1, base1, "0123456789"));
// printf(" %s base %s: %s\n", str2, 
// base2, ft_convert_base(str2, base2, "0123456789"));
// printf(" %s base %s: %s\n", str3, 
// base3, ft_convert_base(str3, base3, "01"));

//     return 0;
// }