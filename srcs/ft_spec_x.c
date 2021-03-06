/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/03 12:04:41 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_put_dec(t_flag *all_mod, __int128_t num, int base)
{
	int			curr;
	char		*base_string;
	__int128_t	dec;

	dec = 1;
	base_string = all_mod->spc == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (num == 0 && (all_mod->spc == 'i' || all_mod->spc == 'd') && \
	all_mod->width >= 0 && all_mod->prc == 0 && all_mod->check_prec == 1)
	{
		ft_helper_id(all_mod);
		return ;
	}
	if ((all_mod->len == 4 || all_mod->len == 3) && \
	(dec = ft_helper(num, base)))
		num < 0 ? num *= -1 : 0;
	else
		while ((dec * base < num) && dec < dec * base && (dec * base > 0))
			dec *= base;
	while (dec > 0)
	{
		((curr = num / dec) == base) ? write(1, "10", 2) : \
		write(1, &base_string[curr], 1);
		num %= dec;
		dec /= base;
	}
}

void			ft_num(t_flag *all_mod, unsigned long long num, int base, \
int len)
{
	if (all_mod->f_sh == '#' && num != 0)
		ft_sharp(all_mod, len);
	else if (all_mod->f_min != '-' && len == 1 && all_mod->prc > 0)
		all_mod->res += ft_wx(all_mod->prc - 1, '0');
	else if (all_mod->width > len && all_mod->f_0 == 'N' \
	&& all_mod->f_sh == '#' && all_mod->prc == -1)
		all_mod->res += ft_wx(all_mod->width - len, '0');
	if (all_mod->spc == 'o' && num == 0 && all_mod->f_sh == '#')
	{
		ft_wx(len, '0');
		return ;
	}
	else if (num == 0 && all_mod->prc == 0)
	{
		ft_wx(len, ' ');
		return ;
	}
	ft_put_dec(all_mod, num, base);
}

void			ft_spec_x(t_flag *all_mod, int len)
{
	if (all_mod->f_min == '-' && all_mod->prc > len && all_mod->f_sh != '#')
		all_mod->res += ft_wx(all_mod->width - (all_mod->prc - len) - len, ' ');
	else if (all_mod->f_min == '-' && all_mod->prc > len && \
	all_mod->f_sh == '#')
	{
		all_mod->res += ft_wx(all_mod->width - (all_mod->prc - 2) - len, '0');
		(len == 1) ? all_mod->res += \
		ft_wx(all_mod->width - all_mod->prc, ' ') : 0;
	}
	else if (all_mod->width > all_mod->prc && all_mod->prc > len \
	&& all_mod->f_sh != '#')
		all_mod->res += ft_wx(all_mod->width - all_mod->prc, ' ');
	else if ((all_mod->width - all_mod->prc > all_mod->width - len) && \
	(all_mod->width > all_mod->prc && all_mod->width > len))
		all_mod->res += ft_wx(all_mod->width - len, ' ');
	else if (all_mod->width - all_mod->prc > len && all_mod->f_min != '-')
	{
		all_mod->res += ft_wx(all_mod->width - all_mod->prc, ' ');
		(len != 1) ? all_mod->res += \
		ft_wx(all_mod->width - all_mod->prc, '0') : 0;
	}
	else if (all_mod->prc > 0 && all_mod->f_sh == '#')
		all_mod->res += ft_wx(all_mod->prc - len, ' ');
	else if (all_mod->prc > 0 && len != 1)
		all_mod->res += ft_wx(all_mod->prc - len, '0');
}

int				ft_spec_x_add(t_flag *all_mod, int len)
{
	if (all_mod->prc < 1 && all_mod->width > len && all_mod->f_0 == 'N' \
	&& all_mod->f_sh != '#' && all_mod->f_min != '-')
		return (ft_wx(all_mod->width - len, '0'));
	else if ((all_mod->prc < 1 && all_mod->width > len && all_mod->f_0 != 'N') \
	|| (len > all_mod->prc && all_mod->f_min == '-'))
		return (ft_wx(all_mod->width - len, ' '));
	else if (all_mod->width > all_mod->prc && all_mod->width > len && \
	all_mod->f_sh != '#' && all_mod->prc > -1 && all_mod->f_min != '-')
		return (ft_wx(all_mod->prc - len, '0'));
	else if (all_mod->width > all_mod->prc && all_mod->width > len \
	&& all_mod->f_0 == 'N' && all_mod->prc > -1 && all_mod->f_min != '-')
		return (ft_wx(all_mod->width - len, '0'));
	else if (len == 1 && all_mod->prc > -1)
	{
		all_mod->res += ft_wx(all_mod->width - all_mod->prc + len, '0');
		return (ft_wx(all_mod->width - all_mod->prc, ' '));
	}
	else if (all_mod->prc > -1 && all_mod->f_sh == '#' && all_mod->spc != 'o')
		return (ft_wx(all_mod->width - all_mod->prc - 2, ' '));
	else if (all_mod->prc > -1)
		return (ft_wx(all_mod->width - all_mod->prc, ' '));
	return (0);
}

void			ft_x(t_flag *all_mod, unsigned long long num, int base, int len)
{
	if (ft_memchr("oxXub", (int)all_mod->spc, 5))
	{
		if (all_mod->width > all_mod->prc && all_mod->width > len \
		&& all_mod->prc > 0 && all_mod->f_min != '-')
		{
			ft_spec_x(all_mod, len);
			(all_mod->prc > 0 && len != 1 && all_mod->f_sh != '#') ? \
			all_mod->res += ft_spec_x_add(all_mod, len) : 0;
		}
		else if (all_mod->f_min == '-' && all_mod->f_sh != '#')
			all_mod->res += ft_wx(all_mod->prc - len, '0');
		else if (all_mod->prc > 0 && all_mod->f_sh != '#')
			ft_spec_x(all_mod, len);
		else if (all_mod->width > len && all_mod->f_min != '-')
			all_mod->res += ft_spec_x_add(all_mod, len);
		ft_num(all_mod, num, base, len);
		if (all_mod->width > all_mod->prc && len > 1 && all_mod->f_min == '-')
			all_mod->res += ft_spec_x_add(all_mod, len);
		else if (all_mod->width > len && all_mod->f_min == '-')
			ft_spec_x(all_mod, len);
	}
	else
		all_mod->res += base_put(all_mod, num, base);
}
