/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:23:42 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:35 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	return (write(fd, &c, 1));
}

ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	printed;

	printed = 0;
	if (!s || fd < 0)
		return (-1);
	printed += ft_putstr_fd(s, fd);
	if (printed < 0)
		return (printed);
	printed += ft_putchar_fd('\n', fd);
	if (printed < 0)
		return (printed);
	return (printed);
}
