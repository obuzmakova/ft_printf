/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/03/02 22:25:22 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width(t_flag *all_mod, int len)
{
	if (all_mod->width != 0 && all_mod->width > len)
	{
		while (all_mod->width != len)
		{
			write(1, " ", 1);
			all_mod->width--;
			all_mod->res++;
		}
	}
	return (0);
}

void	ft_percent(t_flag *all_mod)
{
	if (all_mod->f_min == '-')
	{
		write(1, "%", 1);
		all_mod->res++;
	}
	if (all_mod->f_0 == 'N' && all_mod->f_min != '-')
	{
		while (all_mod->width != 1)
		{
			write(1, "0", 1);
			all_mod->width--;
			all_mod->res++;
		}
	}
	else
		ft_width(all_mod, 1);
	if (all_mod->f_min != '-')
	{
		write(1, "%", 1);
		all_mod->res++;
	}
}

int		ft_simple_width(int simple_width, t_flag *all_mod)
{
	while (simple_width)
	{
		write(1, " ", 1);
		simple_width--;
		all_mod->res++;
	}
	return (0);
}

int		ft_spec_c(va_list all_arg, t_flag *all_mod)
{
	char	c;

	c = (char)va_arg(all_arg, int);
	if (all_mod->f_min == '-')
		ft_putchar(c);
	ft_width(all_mod, 1);
	if (all_mod->f_min != '-')
		ft_putchar(c);
	all_mod->res = all_mod->res + 1;
	return (0);
}
