/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/02/29 20:59:31 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_space(t_flag *all_mod, char *sign, int len)
{
	if (((*sign != '-') && all_mod->f_pl != '+' && all_mod->width <= len && all_mod->prc == -1) \
	|| (all_mod->f_sp == 'S' && (*sign != '-') && all_mod->f_min == '-'))
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->prc >= len && all_mod->f_pl != '+' && all_mod->width == 0 && (*sign != '-'))
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->prc < len && all_mod-> prc > 0 && all_mod->width == 0 && (*sign != '-') && all_mod->f_min != '-' && all_mod->f_pl != '+')
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->f_0 == 'N' && (*sign != '-') && all_mod->f_pl != '+' && all_mod->prc == -1)
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->width < len && (*sign != '-') && all_mod->f_pl != '+')
		all_mod->res += ft_wx(1, ' ');
	else
		return;
}