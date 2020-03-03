/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/03 20:13:23 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_spec_id(t_flag *all_mod, int len)
{
	if (all_mod->f_min != '-')
	{
		if (all_mod->f_0 != 'N' && all_mod->width <= len && all_mod->prc <= len)
			write(1, "-", 1);
		else if (all_mod->f_0 != 'N' && all_mod->width > all_mod->prc \
		&& all_mod->prc == -1)
			write(1, "-", 1);
	}
}

void	ft_negative(t_flag *all_mod, char *sign, int len)
{
	if (all_mod->spc == 'd' && all_mod->prc > 0 && len > all_mod->prc && \
	all_mod->width > len && all_mod->f_0 == '0' && all_mod->f_sh == '0')
		all_mod->res += ft_wx(all_mod->width - len, ' ');
	else if ((all_mod->prc <= len && all_mod->f_pl != '+') || \
	(all_mod->f_pl == '+' && all_mod->f_0 == 'N' && (*sign == '-') && \
	all_mod->prc < len) || (all_mod->f_pl == '+' && all_mod->f_0 == 'N' \
	&& (*sign != '-') && all_mod->prc < len))
		all_mod->res += ft_wx(all_mod->width - all_mod->prc - 2, ' ');
	else
		all_mod->res += ft_wx(all_mod->width - all_mod->prc - 1, ' ');
	if (*sign == '-')
		write(1, sign, 1);
	else if (all_mod->f_pl == '+')
		write(1, "+", 1);
	((*sign == '-') && all_mod->f_pl == '+') ? (all_mod->res += \
	ft_wx(all_mod->prc - len + 2, '0')) : (all_mod->res += \
	ft_wx(all_mod->prc - len + 1, '0'));
}

void	to_spec_plus(t_flag *all_mod, int len)
{
	if ((all_mod->prc > len) || (all_mod->f_0 == 'N') || \
	(all_mod->f_pl == '+' && all_mod->width > len && all_mod->prc > 0))
		return ;
	else
		write(1, "+", 1);
}

void	ft_doublesign(t_flag *all_mod, char *sign, int len)
{
	(*sign == '-') ? write(1, sign, 1) : write(1, "+", 1);
	if (all_mod->prc >= len)
	{
		(*sign == '-') ? ft_wx(1, '0') : 0;
		all_mod->res += ft_wx(all_mod->prc - len + 1, '0');
	}
}

void	ft_doublesignend(t_flag *all_mod, char *sign, int len)
{
	if (all_mod->width > all_mod->prc && all_mod->prc >= len)
		all_mod->res += ft_wx(all_mod->width - all_mod->prc - 1, ' ');
	if (all_mod->prc < len && (len < all_mod->width || len < all_mod->prc))
	{
		if (*sign == '-')
			all_mod->res += ft_wx(len - all_mod->prc, ' ');
		else
			all_mod->res += ft_wx(len - all_mod->prc + 1, ' ');
	}
}
