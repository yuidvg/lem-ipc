/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:09:57 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 17:13:53 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	printed;

	printed = 0;
	if (n < 0)
	{
		printed += ft_putchar_fd('-', fd);
		return (printed + ft_putunbr_fd((unsigned int)(n * -1), UDECIMAL, fd));
	}
	if (n >= 10)
		printed += ft_putnbr_fd(n / 10, fd);
	printed += ft_putchar_fd(UDECIMAL[n % 10], fd);
	return (printed);
}

ssize_t	ft_putunbr_fd(unsigned int n, char *digits, int fd)
{
	ssize_t	printed;
	size_t	base;

	if (!digits || fd < 0)
		return (-1);
	base = ft_strlen(digits);
	if (base < 2 || base > 16)
		return (-1);
	printed = 0;
	if (n >= base)
		printed += ft_putunbr_fd(n / base, digits, fd);
	printed += ft_putchar_fd(digits[n % base], fd);
	return (printed);
}
