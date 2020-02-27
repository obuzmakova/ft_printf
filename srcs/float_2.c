/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:08:47 by soyster           #+#    #+#             */
/*   Updated: 2020/02/27 16:15:36 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_act_width(t_float *fl, t_flag *all_mod)
{
	int	act_width;

	act_width = fl->len_wh +
	(all_mod->prc != 0 ? +all_mod->prc : +0) + (all_mod->prc != 0 ? +1 : +0)
	+ ((fl->ch_s == 1 || all_mod->f_pl == '+') ? +1 : +0)
	+ ((all_mod->f_sh == '#' && all_mod->prc == 0) ? +1 : +0)
	+ ((all_mod->f_sp == 'S' && !fl->ch_s) ? +1 : +0);
	return (act_width);
}

void	ft_print_sp(t_float *fl, t_flag *all_mod)
{
	int	act_width;

	if (all_mod->f_sp == 'S' && !fl->ch_s && all_mod->f_pl == '0'
	&& all_mod->f_min != '-')
	{
		write(1, " ", 1);
		all_mod->res = all_mod->res + 1;
	}
	act_width = ft_act_width(fl, all_mod);
	if (all_mod->width)
	{
		fl->len_wh = ft_len_whole(fl->n_st);
		while (--all_mod->width > act_width)
		{
			if (all_mod->f_0 != 'N' || (all_mod->f_0 == 'N'
			&& all_mod->f_min == '-'))
				write(1, " ", 1);
			else
				write(1, "0", 1);
			all_mod->res = all_mod->res + 1;
		}
	}
}

void	ft_print_fl(t_float *fl, t_flag *all_mod)
{
	if (fl->ch_s == 1 && all_mod->f_0 != 'N')
	{
		write(1, "-", 1);
		all_mod->res = all_mod->res + 1;
	}
	if (all_mod->f_pl == '+' && !fl->ch_s && all_mod->f_0 != 'N')
	{
		write(1, "+", 1);
		all_mod->res = all_mod->res + 1;
	}
	ft_putlongnbr(fl->n_st, all_mod);
	if (all_mod->prc != 0 || all_mod->f_sh == '#')
	{
		write(1, ".", 1);
		all_mod->res = all_mod->res + 1;
	}
	while (fl->k < all_mod->prc)
		ft_putlongnbr(fl->frt[fl->k++], all_mod);
}

void	ft_putlongnbr(long n, t_flag *all_mod)
{
	if (n < 0)
	{
		write(1, "-", 1);
		all_mod->res++;
		n = n * -1;
	}
	if (n > 9)
		ft_putlongnbr(n / 10, all_mod);
	ft_putchar(n % 10 + '0');
	all_mod->res++;
}
