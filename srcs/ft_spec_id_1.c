/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/03 20:45:20 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_space(t_flag *all_mod, char *sign, int len)
{
	if (((*sign != '-') && all_mod->f_pl != '+' && all_mod->width <= len && \
	all_mod->prc == -1) || (all_mod->f_sp == 'S' && (*sign != '-') && \
	all_mod->f_min == '-'))
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->prc >= len && all_mod->f_pl != '+' && all_mod->width == 0\
	&& (*sign != '-'))
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->prc < len && all_mod->prc > 0 && all_mod->width == 0 && \
	(*sign != '-') && all_mod->f_min != '-' && all_mod->f_pl != '+')
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->f_0 == 'N' && (*sign != '-') && all_mod->f_pl != '+' && \
	all_mod->prc == -1)
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->width < len && (*sign != '-') && all_mod->f_pl != '+')
		all_mod->res += ft_wx(1, ' ');
	else if (all_mod->width < all_mod->prc && all_mod->prc > 0 && all_mod->width
	> len && all_mod->f_pl == '0' && all_mod->f_min == '0' && \
	all_mod->f_sh == '0' && all_mod->f_pl == '0')
		all_mod->res += ft_wx(1, ' ');
	else
		return ;
}

int			count_for_len_llu(unsigned long long nbr, int base)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr /= base;
		count += 1;
	}
	return (count);
}

void		check_zero(t_flag *all_mod, char *sign, int len)
{
	if (*sign == '-')
		ft_negative(all_mod, sign, len);
	else if (all_mod->width > all_mod->prc && all_mod->prc > len)
		all_mod->res += ft_wx(all_mod->width - all_mod->prc, ' ');
	else if (all_mod->width > all_mod->prc && all_mod->prc < -1)
		all_mod->res += ft_wx(all_mod->width - len, '0');
	else if (all_mod->width > all_mod->prc && all_mod->prc < len)
		all_mod->res += ft_wx(all_mod->width - len, ' ');
	else
		all_mod->res += ft_wx(all_mod->width - len, '0');
	(*sign != '-') ? all_mod->res += ft_wx(all_mod->prc - len, '0') : 0;
}

void		ft_sign_dig(t_flag *all_mod, char *sign, int len)
{
	if ((all_mod->width <= all_mod->prc && (all_mod->prc > len || \
	(all_mod->f_0 == 'N'))) || ((all_mod->prc == -1 && all_mod->f_0 == 'N')))
		write(1, sign, 1);
	else if (all_mod->f_min == '-' && (*sign == '-'))
		write(1, sign, 1);
}

void		ft_llu(t_flag *all_mod, unsigned long long num, int base, int len)
{
	char	*base_string;
	size_t	dec;
	int		curr;

	dec = 1;
	base_string = all_mod->spc == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	all_mod->res += len;
	(num == 0) ? all_mod->res += 1 : 0;
	ft_helper_ll(all_mod, len);
	(all_mod->spc == 'x' && all_mod->f_sh == '#' && all_mod->f_0 == '0') ? \
	write(1, "0x", 2) : 0;
	(all_mod->spc == 'X' && all_mod->f_sh == '#' && all_mod->f_0 == '0') ? \
	write(1, "0X", 2) : 0;
	while ((dec * base < num) && dec < dec * base && (dec * base > 0))
		dec *= base;
	while (dec > 0)
	{
		((curr = num / dec) == base) ? write(1, "10", 2) :\
		write(1, &base_string[curr], 1);
		num %= dec;
		dec /= base;
	}
	if (all_mod->width > len && all_mod->f_min == '-')
		all_mod->res += ft_wx(all_mod->width - len, ' ');
}
