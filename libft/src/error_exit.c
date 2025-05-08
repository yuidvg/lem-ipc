/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:16:35 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:35 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(ssize_t code, void *asnd_0, void *asnd_1, void *asnd_2)
{
	if (code == -1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	free(asnd_0);
	free(asnd_1);
	free(asnd_2);
	exit (code);
}
