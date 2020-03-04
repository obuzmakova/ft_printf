/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/03 20:46:48 by mleticia         ###   ########.fr       */
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

void		ft_helper_sign(t_flag *all_mod, char *sign, int len)
{
	all_mod->res += ft_wx(all_mod->width - len, ' ');
	(all_mod->f_pl == '+' && (*sign == '-')) ? all_mod->res += \
	ft_wx(1, ' ') : 0;
	(all_mod->f_pl == '+' && (*sign != '-')) ? write(1, "+", 1) \
	: write(1, sign, 1);
}

void		ft_digit2_part2(t_flag *all_mod, int len)
{
	(all_mod->f_0 == 'N') ? (all_mod->res += ft_wx(all_mod->width - len, \
	'0')) : (all_mod->res += ft_wx(all_mod->width - len, ' '));
}

void		ft_helper_ll(t_flag *all_mod, int len)
{
	if ((all_mod->spc == 'x' || all_mod->spc == 'X') && all_mod->f_sh == '#')
	{
		all_mod->width -= 2;
		all_mod->res += 2;
		(all_mod->f_0 == 'N' && all_mod->spc == 'x') ? write(1, "0x", 2) : 0;
		(all_mod->f_0 == 'N' && all_mod->spc == 'X') ? write(1, "0X", 2) : 0;
	}
	(all_mod->spc == 'o' && all_mod->f_sh == '#' && all_mod->width == 0) ? \
	all_mod->res += ft_wx(1, '0') : 0;
	if (all_mod->width > len && all_mod->f_min != '-' && all_mod->spc != 'o')
		(all_mod->f_0 == 'N') ? (all_mod->res += ft_wx(all_mod->width - len,\
		'0')) : (all_mod->res += ft_wx(all_mod->width - len, ' '));
	if (all_mod->spc == 'o' && all_mod->width > len)
	{
		((all_mod->f_0 != 'N' && all_mod->f_sh == '#') || (all_mod->f_sh == '0'\
		&& all_mod->f_0 == '0')) ? (all_mod->res += ft_wx(all_mod->width - len\
		- 1, ' ')) : (all_mod->res += ft_wx(all_mod->width - len - 1, '0'));
		(all_mod->f_sh == '#' || all_mod->f_0 == 'N') ? \
		(all_mod->res += ft_wx(1, '0')) : (all_mod->res += ft_wx(1, ' '));
	}
	if (all_mod->prc > len && all_mod->check_prec == 1)
		all_mod->res += ft_wx(all_mod->prc - len, '0');
}
