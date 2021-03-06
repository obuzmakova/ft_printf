/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/02/29 20:01:24 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_check(t_flag *all_mod, long long nbr)
{
	if ((all_mod->spc == 'x' || all_mod->spc == 'X') && nbr != 0 \
	&& all_mod->f_sh == '#')
		return (2);
	if (all_mod->spc == 'o' && nbr != 0 && all_mod->f_sh == '#')
		return (1);
	if (all_mod->f_pl == '+' && nbr < 0 && all_mod->prc == -1)
		return (0);
	if (all_mod->f_pl == '+')
		return (1);
	return (0);
}

void		ft_zero(t_flag *all_mod)
{
	if (all_mod->spc == 'o' && all_mod->f_sh == '#' && all_mod->width == 0 \
	&& all_mod->prc == 0)
		write(1, "0", 1);
	else if (all_mod->width == 0 && all_mod->prc == 0)
		all_mod->res -= 1;
	else if (all_mod->width <= 0 && all_mod->prc <= 0)
		write(1, "0", 1);
}

int			ft_wx(int len, char c)
{
	int		res;

	if (len < 0)
		return (0);
	res = len;
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
	}
	return (res);
}

int			base_put(t_flag *all_mod, long long num, int base)
{
	int		i;
	char	*base_string;

	i = 0;
	base_string = all_mod->spc == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (num > 0)
	{
		write(1, &base_string[num % base], 1);
		num /= base;
		i++;
	}
	return (i);
}

int			ft_sharp(t_flag *all_mod, int len)
{
	(all_mod->spc == 'o' && all_mod->f_min != '-' && all_mod->width > \
	all_mod->prc && all_mod->prc > len) ? all_mod->res += ft_wx(1, ' ') : 0;
	if (all_mod->spc == 'x')
		write(1, "0x", 2);
	else if (all_mod->spc != 'o')
		write(1, "0X", 2);
	else
		write(1, "0", 1);
	if (all_mod->prc > len && all_mod->spc == 'o')
		all_mod->res += ft_wx(all_mod->prc - len, '0');
	else if (all_mod->prc > len - 2 && all_mod->spc != 'o')
		all_mod->res += ft_wx(all_mod->prc - len + 2, '0');
	else if (all_mod->prc == -1 && all_mod->width > len && all_mod->f_0 == 'N' \
	&& all_mod->f_min == '0')
		all_mod->res += ft_wx(all_mod->width - len, '0');
	return (0);
}
