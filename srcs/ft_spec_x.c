//
// Created by Magorian Leticia on 04/02/2020.
//

#include "../includes/ft_printf.h"

int	ft_widthx(int len, char c)
{
	int res;

	res = len;
	/*while (width > len)
	{
		if (width > prec && prec >= 0)
			write(1, " ", 1);
		else if (width > prec)
			write(1, "0", 1);
		width--;
	}
	while (len < prec)
	{
		write(1, "0", 1);
		prec--;
	}*/
	while (len > 0)
	{
		write (1, &c, 1);
		len--;
	}
	return (res);
}

int	ft_spec_x(t_flag *all_mod, long long num, int len, char *base_string)
{
	if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->flag_0 == 'N')
		return(ft_widthx(all_mod->width - len, '0'));
	else if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->precision == -1)
		return(ft_widthx(all_mod->width - len, ' '));
	else if ((all_mod->width > all_mod->precision && all_mod->width > len) && \
		(all_mod->width - all_mod->precision > all_mod->width - len))
		return(ft_widthx(all_mod->width - len, ' '));
	else if (all_mod->width - all_mod->precision > len && all_mod->flag_min != '-')
	{
		all_mod->result += ft_widthx(all_mod->width - all_mod->precision, ' ');
		return(ft_widthx(all_mod->precision - len, '0'));
	}
	else if (all_mod->precision > 0)
		return(ft_widthx(all_mod->precision - len, '0'));
	if (all_mod->flag_sh == '#')
	{
		if(all_mod->specifier == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		return(2);
	}
	return(0);
}
