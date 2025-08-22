/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:30:28 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:31:32 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dispatcher(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_uint(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex_uint(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, unsigned long)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
	{
		return (write(1, &c, 1));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		index;
	int		ret;

	index = 0;
	counter = 0;
	va_start(args, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
		{
			index++;
			ret = dispatcher(format[index], args);
		}
		else
			ret = write(1, &format[index], 1);
		if (ret == -1)
			return (-1);
		counter += ret;
		index++;
	}
	va_end(args);
	return (counter);
}
