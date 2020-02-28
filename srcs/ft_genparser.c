/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:57:33 by soyster           #+#    #+#             */
/*   Updated: 2020/02/28 22:01:30 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_flags(va_list all_arg, t_flag *all_mod)
{
	while (all_mod->format[all_mod->i] == '#' || \
	all_mod->format[all_mod->i] == '0' || all_mod->format[all_mod->i] == '-' \
	|| all_mod->format[all_mod->i] == '+' || all_mod->format[all_mod->i] == ' ')
	{
		if (all_mod->format[all_mod->i] == '#')
			all_mod->f_sh = '#';
		if (all_mod->format[all_mod->i] == '0')
			all_mod->f_0 = 'N';
		if (all_mod->format[all_mod->i] == '-')
			all_mod->f_min = '-';
		if (all_mod->format[all_mod->i] == '+')
			all_mod->f_pl = '+';
		if (all_mod->format[all_mod->i] == ' ')
			all_mod->f_sp = 'S';
		all_mod->i++;
	}
	return (0);
}

int		ft_write_befpercent(va_list all_arg, t_flag *all_mod)
{
	while (all_mod->format[all_mod->i] && all_mod->format[all_mod->i] != '%')
	{
		if (all_mod->format[all_mod->i] == '{')
		{
			ft_color(all_mod);
			ft_eoc(all_mod);
		}
		else if (all_mod->format[all_mod->i] != '%')
		{
			write(1, &(all_mod->format[all_mod->i]), 1);
			all_mod->i++;
			all_mod->res++;
		}
	}
	if (!all_mod->format[all_mod->i])
		return (0);
	all_mod->i++;
	return (0);
}

void	ft_fill_struct(t_flag *all_mod, char *format, size_t len)
{
	all_mod->format = format;
	all_mod->i = 0;
	all_mod->res = 0;
	all_mod->f_sh = '0';
	all_mod->f_0 = '0';
	all_mod->f_min = '0';
	all_mod->f_pl = '0';
	all_mod->f_sp = '0';
	all_mod->width = 0;
	all_mod->check_prec = 0;
	all_mod->prc = -1;
	all_mod->len = 0;
	all_mod->spc = '0';
}

void	ft_free_allmod(t_flag *all_mod)
{
	all_mod->f_sh = '0';
	all_mod->f_0 = '0';
	all_mod->f_min = '0';
	all_mod->f_pl = '0';
	all_mod->f_sp = '0';
	all_mod->width = 0;
	all_mod->check_prec = 0;
	all_mod->prc = -1;
	all_mod->len = 0;
	all_mod->spc = '0';
}

int		ft_gen_parser(va_list all_arg, char *format)
{
	t_flag	all_mod;
	int		res;

	ft_fill_struct(&all_mod, format, ft_strlen(format));
	while (all_mod.format[all_mod.i] != '\0')
	{
		ft_write_befpercent(all_arg, &all_mod);
		if (!(all_mod.format[all_mod.i]))
			return (all_mod.res);
		ft_flags(all_arg, &all_mod);
		ft_wid_and_prec(all_arg, &all_mod);
		ft_length(all_arg, &all_mod);
		ft_spec(all_arg, &all_mod);
		ft_findfunction(all_arg, &all_mod);
		ft_eoc(&all_mod);
		ft_free_allmod(&all_mod);
	}
	res = all_mod.res;
	return (res);
}
