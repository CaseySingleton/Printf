/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:12:48 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/30 17:12:53 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_buffer(t_pf *pf, int bytes)
{
	write(1, pf->buffer, bytes);
	ft_bzero(pf->buffer, PF_BUFF_SIZE);
	pf->buffer_index = 0;
}

void			write_to_buffer(t_pf *pf, char *addition, int bytes)
{
	if (addition == NULL || bytes == 0)
		return ;
	if (pf->buffer_index + bytes >= PF_BUFF_SIZE)
		print_buffer(pf, PF_BUFF_SIZE);
	ft_memcpy(pf->buffer + pf->buffer_index, addition, bytes);
	pf->buffer_index += bytes;
	pf->total_bytes += bytes;
}
