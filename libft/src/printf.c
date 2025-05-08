/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:02:49 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 17:14:45 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_putptr_fd(uintptr_t ptr, const char *base, int fd)
{
	ssize_t	printed;

	printed = 0;
	if (ptr >= 16)
		printed += ft_putptr_fd(ptr / 16, base, fd);
	else
		printed += ft_putstr_fd("0x", fd);
	printed += ft_putchar_fd(base[ptr % 16], fd);
	return (printed);
}

ssize_t	putfmtd_fd(char exp, va_list ap, int fd)
{
	if (exp == 'c')
		return (ft_putchar_fd((char)va_arg(ap, int), fd));
	if (exp == 's')
		return (ft_putstr_fd(va_arg(ap, char *), fd));
	if (exp == 'p')
		return (ft_putptr_fd((uintptr_t)va_arg(ap, void *), UHEX_L, fd));
	if (exp == 'P')
		return (ft_putptr_fd((uintptr_t)va_arg(ap, void *), UHEX_U, fd));
	if (exp == 'd' || exp == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), fd));
	if (exp == 'u')
		return (ft_putunbr_fd(va_arg(ap, unsigned int), UDECIMAL, fd));
	if (exp == 'x')
		return (ft_putunbr_fd(va_arg(ap, unsigned int), UHEX_L, fd));
	if (exp == 'X')
		return (ft_putunbr_fd(va_arg(ap, unsigned int), UHEX_U, fd));
	if (exp == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	size_t	i;
	ssize_t	printed;

	i = 0;
	printed = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			printed += ft_putchar_fd(fmt[i], fd);
		else
		{
			i++;
			printed += putfmtd_fd(fmt[i], ap, fd);
		}
		i++;
	}
	return (printed);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	size_t	printed;

	va_start(ap, fmt);
	printed = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	printed;

	va_start(ap, fmt);
	printed = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (printed);
}
