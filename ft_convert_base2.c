/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:45:29 by jainavas          #+#    #+#             */
/*   Updated: 2024/09/27 18:40:23 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*print_number(char *buffer, long int unbr, char *base, int nbase)
{
	unsigned int	i;
	char			temp;

	i = 0;
	if (unbr == 0)
	{
		buffer[0] = base[0];
		buffer[1] = '\0';
		return (buffer);
	}
	while (unbr > 0)
	{
		buffer[i++] = base[unbr % nbase];
		unbr /= nbase;
	}
	buffer[i] = '\0';
	i = 0;
	while (i < ft_strlen(buffer) / 2)
	{
		temp = buffer[i];
		buffer[i] = buffer[ft_strlen(buffer) - 1 - i];
		buffer[ft_strlen(buffer) - 1 - i] = temp;
		i++;
	}
	return (buffer);
}

char	*ft_putnbr_base(unsigned long nbr, char *base)
{
	int			nbase;
	char		*buffer;
	long int	lnbr;

	if (!debugbase(base))
		return ((void *)0);
	buffer = malloc(sizeof(char) * 21);
	if (!buffer)
		return ((void *)0);
	nbase = (int)ft_strlen(base);
	lnbr = nbr;
	if (lnbr < 0)
	{
		buffer[0] = '-';
		buffer = print_number(buffer + 1, -lnbr, base, nbase);
	}
	else
		buffer = print_number(buffer, lnbr, base, nbase);
	return (buffer);
}
