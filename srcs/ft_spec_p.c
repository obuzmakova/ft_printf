/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/03/03 17:46:00 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_spec_p(t_flag *all_mod, long long num, int len)
{
	(all_mod->width > len + 2 && all_mod->f_min != '-') ? \
	all_mod->res += ft_wx(all_mod->width - len - 2, ' ') : 0;
	write(1, "0x", 2);
	all_mod->res += 2;
	if (all_mod->check_prec == 1)
	{
		if (all_mod->prc == 0 && num == 0)
		{
			all_mod->res -= 1;
			return (0);
		}
		else if (all_mod->prc > len)
			all_mod->res += ft_wx(all_mod->prc - len, '0');
	}
	ft_put_dec(all_mod, num, 16);
	(all_mod->width > (len + 2) && all_mod->f_min == '-') ? \
	all_mod->res += ft_wx(all_mod->width - len - 2, ' ') : 0;
	return (0);
}
