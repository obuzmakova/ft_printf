/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/02/20 21:18:47 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include "float.h"

int		ft_len_whole(long num_start)
{
	int	len_whole;

	len_whole = 1;
	while(num_start / 10 > 0)
	{
		num_start = num_start / 10; 
		len_whole++;
	}
	return (len_whole);
}

int		ft_rounding(t_flag *all_mod)
{
	int a;
	
	//a = all_mod->fractional[all_mod->index];
	//all_mod->index--;
	all_mod->fractional[all_mod->index] = all_mod->fractional[all_mod->index] + 1;
	if (all_mod->fractional[all_mod->index] == 10)
	{
		all_mod->fractional[all_mod->index] = 0;
		all_mod->index--;
		if (all_mod->index != -1)
			ft_rounding(all_mod);
		else
			return (1);
	}
	else
		return (0);
	if (all_mod->index == -1)
		return (1);
	else
		return (0);
}

void	ft_spec_f(va_list all_arg, t_flag *all_mod)
{
	long double f;
	long		num_start;
	long double	num_end;
	int			digit;
	//int		*fractional;
	//int			index;
	//char		digit;
	int			k;
	int			check_sign;
	int			len_whole;

	check_sign = 0;	
	k = 0;
	if (all_mod->length == 5)
		f = va_arg(all_arg, long double);
	else
		f = va_arg(all_arg, double);
	num_start = (long)f;
	//ft_printf("%ld", num_start);
	//write(1, ".", 1);
	if (num_start < 0)
	{
		f = f * -1;
		num_start = num_start * -1;
		check_sign = 1;
	}
	num_end = f - num_start;
	if (num_end < 0)
	{
		check_sign = 1;
		num_end = num_end * (-1);
	}
	all_mod->index = 0;
	if (all_mod->precision == -1)
		all_mod->precision = 6;
	all_mod->fractional = (int*)malloc((all_mod->precision + 1) * sizeof(int));
	if (all_mod->precision == 0)
		all_mod->fractional[all_mod->index] = (int)(num_end * 10);
	while (all_mod->index < all_mod->precision)
	{
		//digit = (int)(num_end * 10);
		all_mod->fractional[all_mod->index] = (int)(num_end * 10);
		//fractional[index] = 1;
		//ft_printf("%i", fractional[index]); //поменять на наш printf
		num_end = num_end * 10;
		num_end = num_end - all_mod->fractional[all_mod->index];
		all_mod->index++;
	}
	//index--;
	//if (all_mod->length == 3 && (int)(num_end * 100) % 10 == 9) //
	//	num_end = num_end + 0.01; //
	{
		if ((int)(num_end * 10) > 4) 
		{
			all_mod->index--;
			if (ft_rounding(all_mod))
				num_start = num_start + 1;
		}
	}
	if (all_mod->precision == 0)
	{
		if (all_mod->fractional[k] > 4)
			num_start++;
	}
	
	if (check_sign == 1 && all_mod->flag_0 == 'N' && all_mod->flag_min != '-')
		write(1, "-", 1);
	if (all_mod->flag_pl == '+' && !check_sign && all_mod->flag_0 == 'N' && all_mod->flag_min != '-')
		write(1, "+", 1);
	
	//выводит если знак минус

	if (all_mod->flag_min == '-')
	{
		if (all_mod->flag_sp == 'S' && !check_sign) //
			write(1, " ", 1); //
		if (check_sign == 1)
			write(1, "-", 1);
		if (all_mod->flag_pl == '+' && !check_sign)
			write(1, "+", 1);
		ft_printf("%ld", num_start);
	
		if (all_mod->precision != 0 || all_mod->flag_sh == '#')
			write(1, ".", 1);	
		while (k < all_mod->precision)
		{
			ft_printf("%i", all_mod->fractional[k]);
			k++;
		}
	}
	
	if (all_mod->flag_sp == 'S' && !check_sign && all_mod->flag_pl == '0' && all_mod->flag_min != '-') //
		write(1, " ", 1); //

	if (all_mod->width)
	{
		len_whole = ft_len_whole(num_start);
		while (all_mod->width > len_whole + (all_mod->precision != 0 ? + all_mod->precision : + 0) + (all_mod->precision != 0 ? + 1 : + 0) + 
		((check_sign == 1 || all_mod->flag_pl == '+') ? + 1 : + 0) + ((all_mod->flag_sh == '#' && all_mod->precision == 0) ? + 1 : + 0)
		+ ((all_mod->flag_sp == 'S' && !check_sign) ? + 1 : + 0)) //
		{
			if (all_mod->flag_0 != 'N' || (all_mod->flag_0 == 'N' && all_mod->flag_min == '-'))
			{
				write(1, " ", 1);
			}
			else
			{
				write(1, "0", 1);
			}
			all_mod->width--;
		}
	}
	
	// выводит число после ширины
	
	if (all_mod->flag_min != '-')
	{
		//if (all_mod->flag_sp == 'S')// && all_mod->width != '0')
		//	write(1, " ", 1);
		if (check_sign == 1 && all_mod->flag_0 != 'N')
			write(1, "-", 1);
		if (all_mod->flag_pl == '+' && !check_sign && all_mod->flag_0 != 'N')
			write(1, "+", 1);
		
		ft_printf("%ld", num_start);
	
		if (all_mod->precision != 0 || all_mod->flag_sh == '#')
			write(1, ".", 1);	
		while (k < all_mod->precision)
		{
			ft_printf("%i", all_mod->fractional[k]);
			k++;
		}
	}

	
	//printf("%", fractional);
	//printf("%i", DBL_DIG); // количество заничмых чисел
}