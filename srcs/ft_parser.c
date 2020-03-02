/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:57:33 by soyster           #+#    #+#             */
/*   Updated: 2020/03/01 23:00:51 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_c(int num, char s)
{
	int res;

	res = num * 10 + (s - '0');
	return (res);
}

int	ft_wid_prec(t_flag *all_mod)
{
	if (all_mod->format[all_mod->i] == '.')
	{
		all_mod->check_prec = 1;
		all_mod->prc = 0;
		all_mod->i++;
	}
	if (all_mod->check_prec == 0)
	{
		if (!(all_mod->width))
			all_mod->width = all_mod->format[all_mod->i] - '0';
		else
			all_mod->width = ft_c(all_mod->width, all_mod->format[all_mod->i]);
	}
	else
	{
		if (!ft_isdigit(all_mod->format[all_mod->i]))
			return (0);
		if (!all_mod->prc)
			all_mod->prc = all_mod->format[all_mod->i] - '0';
		else
			all_mod->prc = ft_c(all_mod->prc, all_mod->format[all_mod->i]);
	}
	all_mod->i++;
	return (1);
}

int	ft_wid_and_prec(va_list all_arg, t_flag *all_mod)
{
	int check_prec;

	check_prec = 0;
	if (all_mod->format[all_mod->i] == '*' &&
		all_mod->format[all_mod->i + 1] == '.')
	{
		all_mod->width = (int)va_arg(all_arg, int);
		all_mod->i++;
	}
	while (ft_isdigit(all_mod->format[all_mod->i]) \
	|| all_mod->format[all_mod->i] == '.')
		ft_wid_prec(all_mod);
	if (all_mod->format[all_mod->i] == '*')
	{
		all_mod->prc = (int)va_arg(all_arg, int);
		all_mod->i = all_mod->i + 1;
	}
	return (0);
}

int	ft_length(va_list all_arg, t_flag *all_mod)
{
	while (all_mod->format[all_mod->i] == 'h' || all_mod->format[all_mod->i] \
	== 'l' || all_mod->format[all_mod->i] == 'L')
	{
		if (all_mod->len == 1 || all_mod->len == 3)
		{
			if (all_mod->len == 1)
				all_mod->len = 2;
			else
				all_mod->len = 4;
		}
		else
		{
			if (all_mod->format[all_mod->i] == 'h')
				all_mod->len = 1;
			if (all_mod->format[all_mod->i] == 'l')
				all_mod->len = 3;
			if (all_mod->format[all_mod->i] == 'L')
				all_mod->len = 5;
		}
		all_mod->i++;
	}
	return (0);
}

int	ft_spec(va_list all_arg, t_flag *all_mod)
{
	all_mod->spc = all_mod->format[all_mod->i];
	if (all_mod->spc != 'c' && all_mod->spc != 's' && all_mod->spc != 'd'
		&& all_mod->spc != 'i' && all_mod->spc != 'u' && all_mod->spc != 'b'
		&& all_mod->spc != 'o' && all_mod->spc != 'X' && all_mod->spc != 'x'
		&& all_mod->spc != '%' && all_mod->spc != 'f' && all_mod->spc != 'k'
		&& all_mod->spc != 'r' && all_mod->spc != 'p')
		return (0);
	all_mod->i++;
	return (0);
}
