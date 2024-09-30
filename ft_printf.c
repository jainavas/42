/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:37:44 by jainavas          #+#    #+#             */
/*   Updated: 2024/09/30 21:20:46 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	sel_pointer(void *ptr)
{
	int		numw;
	char	*res;

	if (ptr == (void *)-1)
	{
		numw = ft_intputstr_fd("0xffffffffffffffff", 1);
		return (numw);
	}
	if (ptr == NULL)
	{
		numw = ft_intputstr_fd("(nil)", 1);
	}
	else
	{
		numw = ft_intputstr_fd("0x", 1);
		res = ft_convert_base(ft_ultoa((unsigned long)ptr), BASE10, BASE16);
		numw += ft_intputstr_fd(res, 1);
		free(res);
	}
	return (numw);
}

int	sel_op2(char x, va_list args, int numw)
{
	char	*res;

	numw = 0;
	if (x == 'c')
		numw = ft_intputchar_fd(((char)va_arg(args, int)), 1);
	if (x == 's')
		numw = ft_intputstr_fd((va_arg(args, char *)), 1);
	if (x == 'd' || x == 'i')
		numw = ft_intputnbr_fd((va_arg(args, int)), 1);
	if (x == 'u')
	{
		res = ft_ultoa((unsigned long)va_arg(args, unsigned int));
		numw = ft_intputstr_fd(res, 1);
		free(res);
	}
	if (x == '%')
		numw = ft_intputchar_fd('%', 1);
	return (numw);
}

int	sel_op(char x, va_list args, int numw)
{
	long int		hex;
	char			*res;

	numw = 0;
	if (x == '%' || x == 'u' || x == 'd' || x == 's' || x == 'c' || x == 'i')
		return (sel_op2(x, args, numw));
	if (x == 'p')
		numw = sel_pointer((va_arg(args, void *)));
	if (x == 'x')
	{
		hex = va_arg(args, long);
		res = ft_strtolower(ft_convert_base(ft_ltoa(hex), BASE10, BASE16));
		numw = ft_intputstr_fd(res, 1);
		free(res);
	}
	if (x == 'X')
	{
		hex = va_arg(args, long);
		res = ft_strtoupper(ft_convert_base(ft_ltoa(hex), BASE10, BASE16));
		numw = ft_intputstr_fd(res, 1);
		free(res);
	}
	return (numw);
}

int	ft_printf(char const *s, ...)
{
	va_list		args;
	size_t		i;
	int			numw;

	i = 0;
	numw = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			numw += sel_op(s[i + 1], args, numw);
			i = i + 2;
		}
		else
		{
			numw += ft_intputchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (numw);
}


int main()
{
	int a = 0;
	int b = 0;
	char character = 'a';
    int number = 18;
    char *string = "cadena de texto";
    void *pointer = &number; // dirección de memoria de 'number'
    unsigned int hex_lower = 255; // valor para %x
    unsigned int hex_upper = 255; // valor para %X
    int signed_int = -42; // valor para %i
    unsigned int unsigned_int = 42; // valor para %u

    a = ft_printf("hola que tal %c %d %s %p %x %X %i %u %%\n",
                      character,
                      number,
                      string,
                      pointer,
                      hex_lower,
                      hex_upper,
                      signed_int,
                      unsigned_int);

	b = printf("hola que tal %c %d %s %p %x %X %i %u %%\n",
                      character,
                      number,
                      string,
                      pointer,
                      hex_lower,
                      hex_upper,
                      signed_int,
                      unsigned_int);
	printf("1 %d\n", a);
	printf("2 %d\n", b);
	return (0);
}