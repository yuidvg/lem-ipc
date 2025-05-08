/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_allocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:09:42 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:35 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size, void *asnd_0, void *asnd_1, void *asnd_2)
{
	void	*allocated;

	allocated = malloc(size);
	if (!allocated)
		ft_exit(-1, asnd_0, asnd_1, asnd_2);
	return (allocated);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alcd_ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	alcd_ptr = malloc(count * size);
	if (!alcd_ptr)
		return (NULL);
	ft_bzero(alcd_ptr, count * size);
	return (alcd_ptr);
}
