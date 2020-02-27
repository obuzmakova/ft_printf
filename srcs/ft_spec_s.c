/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/02/27 21:09:33 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_len(char const *s, size_t len, t_flag *all_mod)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (i != len)
		{
			ft_putchar(s[i]);
			i++;
			all_mod->res++;
		}
	}
	return ;
}

void	ft_print_s(t_flag *all_mod, int len, char *str, int check_0)
{
	int		len_prec;

	if (all_mod->prc == 0 && !all_mod->width)
		return ;
	if (all_mod->prc == 0 && all_mod->width)
	{
		ft_simple_width(all_mod->width, all_mod);
		return ;
	}
	if (all_mod->prc > 0 && all_mod->prc < len)
		len_prec = all_mod->prc;
	else
		len_prec = len;
	if (all_mod->f_min == '-')
		ft_putstr_len(str, len_prec, all_mod);
	ft_width(all_mod, len_prec);
	if (all_mod->f_min != '-')
		ft_putstr_len(str, len_prec, all_mod);
	if (check_0)
		free(str);
}

int		ft_spec_s(va_list all_arg, t_flag *all_mod)
{
	char	*str;
	int		check_0;

	check_0 = 0;
	str = (char*)va_arg(all_arg, char*);
	if (str == NULL)
	{
		str = (char*)malloc(sizeof(char) * 6);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'u';
		str[3] = 'l';
		str[4] = 'l';
		str[5] = ')';
		check_0 = 1;
	}
	ft_print_s(all_mod, ft_strlen(str), str, check_0);
	return (0);
}