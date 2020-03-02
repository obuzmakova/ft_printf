/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/02 19:23:47 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

__int128_t	ft_helper(__int128_t num, int base)
{
	__int128_t	i;
	__int128_t	dec;

	dec = 1;
	i = num;
	i < 0 ? i *= -1 : i;
	while ((dec * base < i) && (dec * base > 0))
		dec *= base;
	return (dec);
}

void		ft_helper_id(t_flag *all_mod)
{
	if ((all_mod->f_min != '-' && all_mod->width > 1 && all_mod->prc != 0) \
	|| (all_mod->f_min == '-' && all_mod->f_pl == '+'))
		write(1, " ", 1);
	(all_mod->width == 0) ? all_mod->res-- : 0;
}
