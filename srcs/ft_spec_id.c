/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/04 14:57:22 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_wid_with_sign(t_flag *all_mod, char *sign, int len)
{
	if ((*sign == '-') && all_mod->spc == 'd' && all_mod->prc > len)
		all_mod->res += ft_wx(all_mod->prc - len + 1, '0');
	else if (*sign != '-' && all_mod->f_pl != '+')
	{
		if (all_mod->prc > len)
		{
			all_mod->res += ft_wx(all_mod->width - all_mod->prc, ' ');
			all_mod->res += ft_wx(all_mod->prc - len, '0');
		}
		else
			all_mod->res += ft_wx(all_mod->width - len, ' ');
	}
	else if ((*sign == '-') || (all_mod->f_pl == '+'))
	{
		if ((all_mod->prc >= len && all_mod->f_pl == '+' && \
		all_mod->width > all_mod->prc))
			ft_negative(all_mod, sign, len);
		else
			ft_helper_sign(all_mod, sign, len);
	}
}

static void	ft_after_dec(t_flag *all_mod, char *sign, int len)
{
	if (all_mod->f_sp != 'S' && all_mod->f_0 == 'N' && all_mod->f_min == '-' \
	&& (all_mod->prc == -1 || all_mod->prc < len))
		all_mod->res += ft_wx(all_mod->width - len, ' ');
	else if (all_mod->f_sp == 'S' && all_mod->f_0 == 'N' && all_mod->width > len
	&& all_mod->f_min != '-' && ((*sign == '-') || (all_mod->width - len == 1)))
		all_mod->res += ft_wx(all_mod->width - len, '0');
	else if (all_mod->f_sp == 'S' && all_mod->f_0 == 'N' && all_mod->width > len
	&& all_mod->f_min != '-')
		all_mod->res += ft_wx(all_mod->width - len - 1, '0');
	else if (all_mod->f_sp != 'S' && all_mod->f_0 == 'N' && (all_mod->prc == -1\
	|| all_mod->prc < len))
		all_mod->res += ft_wx(all_mod->width - len, '0');
	else if ((all_mod->f_sp == 'S' && all_mod->width > len && all_mod->f_min \
	!= '-') || (all_mod->f_min == '-' && (*sign == '-') && all_mod->prc < len))
		all_mod->res += ft_wx(all_mod->width - len, ' ');
	else if (all_mod->f_sp == 'S' && (all_mod->f_min == '-' && (*sign != '-') &&
	all_mod->width > (len + 1) && all_mod->prc < len))
		all_mod->res += ft_wx(all_mod->width - len - 1, ' ');
	else if (all_mod->f_sp != 'S' && (all_mod->prc < len))
		all_mod->res += ft_wx(all_mod->width - len, ' ');
	else if (((all_mod->f_min == '-' && all_mod->f_sp == 'S') || \
	(*sign == '-')) && all_mod->prc > len)
		all_mod->res += ft_wx(all_mod->width - all_mod->prc - 1, ' ');
	else
		all_mod->res += ft_wx(all_mod->width - all_mod->prc, ' ');
}

static void	ft_wid_and_prc(t_flag *all_mod, char *sign, int len)
{
	if (all_mod->f_min != '-' && all_mod->width > len)
	{
		if (all_mod->f_pl == '+' && all_mod->f_0 == 'N')
			ft_negative(all_mod, sign, len);
		else if (all_mod->prc == len && all_mod->f_0 == 'N' && (*sign != '-') \
		&& all_mod->f_sp == '0' && all_mod->f_sh == '0' && all_mod->f_pl == '0')
			all_mod->res += ft_wx(all_mod->width - len, ' ');
		else if (all_mod->prc > len && all_mod->width < all_mod->prc && \
		all_mod->f_0 == 'N' && (*sign != '-'))
			all_mod->res += ft_wx(all_mod->prc - len, '0');
		else if (all_mod->f_0 == 'N')
			check_zero(all_mod, sign, len);
		else if (*sign == '-' && (all_mod->width - all_mod->prc > len))
			ft_negative(all_mod, sign, len);
		else if (all_mod->prc > 0)
			ft_wid_with_sign(all_mod, sign, len);
		else
			all_mod->res += ft_wx(all_mod->width - len, ' ');
	}
	else if ((all_mod->f_min != '-' && all_mod->prc > len) || \
	(all_mod->f_min == '-' && all_mod->prc > len && all_mod->width > len))
		(*sign != '-') ? (all_mod->res += ft_wx(all_mod->prc - len, '0'))
		: (all_mod->res += ft_wx(all_mod->prc - len + 1, '0'));
	else if (all_mod->f_min == '-' && all_mod->prc > len)
		all_mod->res += ft_wx(all_mod->prc - len, '0');
}

static void	ft_digit_2(t_flag *all_mod, char *sign, long long num, int len)
{
	(all_mod->width > len && all_mod->prc == -1 && all_mod->f_min != '-') \
	? ft_after_dec(all_mod, sign, len) : 0;
	if (all_mod->check_prec == 0 && all_mod->prc > len)
		ft_digit2_part2(all_mod, len);
	else if ((all_mod->width > len && all_mod->prc != -1) || \
	(all_mod->prc > len && all_mod->check_prec == 1))
		ft_wid_and_prc(all_mod, sign, len);
	(num == 0 && all_mod->check_prec == 1 && all_mod->width > 1 && \
	all_mod->prc == 0) ? write(1, " ", 1) : 0;
	if (*sign == '-')
		to_spec_id(all_mod, len);
	else if (all_mod->f_pl == '+')
		to_spec_plus(all_mod, len);
	ft_put_dec(all_mod, num, 10);
	if (all_mod->check_prec == 0 && all_mod->width < 0)
	{
		(all_mod->width < 0) ? all_mod->width *= -1 : 0;
		(all_mod->width > len) ? ft_digit2_part2(all_mod, len) : 0;
	}
	(all_mod->f_sp == 'S' && num == 0 && all_mod->f_pl == '+' && \
	all_mod->f_min != '-' && all_mod->f_0 == 'N' && ((all_mod->width - \
	all_mod->prc - 1) > len)) ? write(1, "0", 1) : 0;
	if (all_mod->f_min == '-' && all_mod->width > len)
		ft_after_dec(all_mod, sign, len);
}

void		ft_digit(t_flag *all_mod, char *sign, long long num, int len)
{
	int		base;

	base = 10;
	if (all_mod->f_min == '-' && all_mod->f_pl == '+')
	{
		ft_doublesign(all_mod, sign, len);
		ft_put_dec(all_mod, num, base);
		ft_doublesignend(all_mod, sign, len);
		return ;
	}
	(all_mod->f_sp == 'S') ? ft_space(all_mod, sign, len) : 0;
	if (*sign == '-')
		ft_sign_dig(all_mod, sign, len);
	else if (all_mod->f_pl == '+' && all_mod->width > len && all_mod->prc != -1)
		write(1, "", 0);
	else if (all_mod->f_pl == '+' && ((all_mod->prc > len && all_mod->width \
	< all_mod->prc) || (all_mod->f_0 == 'N' && all_mod->prc < len)))
		write(1, "+", 1);
	(((all_mod->f_pl == '+') || ((all_mod->f_min == '-') && (*sign == '-'))) \
	&& all_mod->prc > all_mod->width && all_mod->prc > len) ? \
	write(1, "0", 1) : 0;
	ft_digit_2(all_mod, sign, num, len);
}
