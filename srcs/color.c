/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:22:30 by soyster           #+#    #+#             */
/*   Updated: 2020/02/28 22:01:43 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strncmp_st(const char *s1, int k, const char *s2, int n)
{
	int		i;
	int		j;

	if (n == 0)
		return (0);
	i = k;
	j = 0;
	while (s1[i] == s2[j] && j < n - 1 && s1[i] != '\0')
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void	ft_color(t_flag *all_mod)
{
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{black}", 7))
	{
		write(1, "\e[30m", 5);
		all_mod->i = all_mod->i + 7;
	}
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{red}", 5))
	{
		write(1, "\e[31m", 5);
		all_mod->i = all_mod->i + 5;
	}
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{green}", 7))
	{
		write(1, "\e[32m", 5);
		all_mod->i = all_mod->i + 7;
	}
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{yellow}", 8))
	{
		write(1, "\e[33m", 5);
		all_mod->i = all_mod->i + 8;
	}
	ft_color_2(all_mod);
}

void	ft_color_2(t_flag *all_mod)
{
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{darkblue}", 10))
	{
		write(1, "\e[34m", 5);
		all_mod->i = all_mod->i + 10;
	}
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{purple}", 8))
	{
		write(1, "\e[35m", 5);
		all_mod->i = all_mod->i + 8;
	}
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{blue}", 6))
	{
		write(1, "\e[36m", 5);
		all_mod->i = all_mod->i + 6;
	}
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{white}", 7))
	{
		write(1, "\e[37m", 5);
		all_mod->i = all_mod->i + 7;
	}
}

void	ft_eoc(t_flag *all_mod)
{
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{eoc}", 5))
	{
		write(1, "\e[0m", 5);
		all_mod->i = all_mod->i + 5;
	}
}
