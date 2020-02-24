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

void ft_putnum(t_flag *all_mod, long long num, int base, int len, char *base_string)
{
	size_t dec;
	int curr;

	dec = 1;
	if (all_mod->flag_sh == '#' && num != 0)
	{
		if (all_mod->specifier == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		if (all_mod->precision > len - 2)
			all_mod->result += ft_widthx(all_mod->precision - len + 2, '0');
		/*else if (all_mod->width > len && all_mod->flag_0 == 'N')
			all_mod->result += ft_widthx(all_mod->width - len, '0');*/
	}
	else if (all_mod->flag_min != '-' && len == 1 && all_mod->precision > 0)
		all_mod->result += ft_widthx(all_mod->precision - 1, '0');
	if (all_mod->width > len && all_mod->flag_0 == 'N' && all_mod->flag_sh == '#')
		all_mod->result += ft_widthx(all_mod->width - len, '0');
	while ((dec * base < num) && dec < dec * base && (dec * base > 0))
		dec *= base;
	while (dec > 0)
	{
		if ((curr = num / dec) == base)
			write(1, "10", 2);
		else
			write(1, &base_string[curr], 1);
		num %= dec;
		dec /= base;
	}
}

int	ft_spec_x(t_flag *all_mod, int len)
{
	if (all_mod->flag_min == '-' && all_mod->precision > len && all_mod-> flag_sh != '#')
		return(ft_widthx(all_mod->width - (all_mod->precision - len) - len, ' '));
	else if (all_mod->flag_min == '-' && all_mod->precision > len && all_mod-> flag_sh == '#')
		return(ft_widthx(all_mod->width - (all_mod->precision - 2) - len, '0'));
	else if (all_mod->width > all_mod->precision && all_mod->precision > len) //&& all_mod->flag_0 == 'N'
		return(ft_widthx(all_mod->width - all_mod->precision, ' '));
	else if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->precision == -1)
		return(ft_widthx(all_mod->width - len, ' '));
	else if ((all_mod->width > all_mod->precision && all_mod->width > len) && \
		(all_mod->width - all_mod->precision > all_mod->width - len))
		return(ft_widthx(all_mod->width - len, ' '));
	else if (all_mod->width - all_mod->precision > len && all_mod->flag_min != '-')
	{
		all_mod->result += ft_widthx(all_mod->width - all_mod->precision, ' ');
		if (len != 1)
			return(ft_widthx(all_mod->width - all_mod->precision, '0'));
	}
	else if (all_mod->precision > 0 && all_mod->flag_sh == '#')
		return(ft_widthx(all_mod->precision - len, ' '));
	else if (all_mod->precision > 0 && len != 1)
		return(ft_widthx(all_mod->precision - len, '0'));
	return(0);
}

int	ft_spec_x_add(t_flag *all_mod, int len)
{
	if (all_mod->precision < 1 && all_mod->width > len && all_mod->flag_0 == 'N' && all_mod->flag_sh != '#')
		return(ft_widthx(all_mod->width - len, '0'));
	else if (all_mod->precision < 1 && all_mod->width > len && all_mod->flag_0 != 'N')
		return(ft_widthx(all_mod->width - len, ' '));
	else if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->flag_0 == 'N' && \
	all_mod->precision > -1 && all_mod->flag_min != '-') //all_mod->flag_min != '-'
		return(ft_widthx(all_mod->precision - len, '0'));
	else if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->flag_0 == 'N' && \
	all_mod->precision > -1 && all_mod->flag_min != '-') //all_mod->flag_min != '-'
		return(ft_widthx(all_mod->width - len, '0'));
	else if (len == 1 && all_mod->precision > -1)
	{
		all_mod->result += ft_widthx(all_mod->width - all_mod->precision + len, '0');
		return (ft_widthx(all_mod->width - all_mod->precision, ' '));
	}
	else if (len > all_mod->precision && all_mod->precision > -1)
		return (ft_widthx(all_mod->width - len, ' '));
	else if (all_mod->precision > -1 && all_mod->flag_sh == '#')
		return (ft_widthx(all_mod->width - all_mod->precision - 2, ' '));
	else if (all_mod->precision > -1)
		return (ft_widthx(all_mod->width - all_mod->precision, ' '));
	else
		return(0);
}

int base_put(long long num, int base, char *base_string)
{
	int i;

	i = 0;
	while (num > 0) {
		write(1, &base_string[num % base], 1);
		num /= base;
		i++;
	}
	return(i);
}

void ft_findout(t_flag *all_mod, long long num, int base, int len)
{
	char   *base_string;

	base_string = all_mod->specifier == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (ft_memchr("oxXu", (int)all_mod->specifier, 4))
	{
		if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->precision > 0 && \
		all_mod->flag_min != '-')
		{
			all_mod->result += ft_spec_x(all_mod, len);
			if (all_mod->width > all_mod->precision && all_mod->precision > 0 && len != 1) //&& all_mod->flag_0 == 'N'
				all_mod->result += ft_spec_x_add(all_mod, len);
		}
		else if (all_mod->precision > 0 && all_mod->flag_min == '-' && all_mod->flag_sh != '#')
			all_mod->result += ft_widthx(all_mod->precision - len, '0');
		else if (all_mod->precision > 0 && all_mod->flag_sh != '#')
			all_mod->result += ft_spec_x(all_mod, len);
		else if (all_mod->width > len && all_mod->flag_min != '-')
			all_mod->result += ft_spec_x_add(all_mod, len);
		ft_putnum(all_mod, num, base, len, base_string);
		if (all_mod->width > all_mod->precision && len > 1 && all_mod->flag_min == '-' && all_mod->precision > -1)
			all_mod->result += ft_spec_x_add(all_mod, len);
		else if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->flag_min == '-')
			all_mod->result += ft_spec_x(all_mod, len);
	}
	else
		all_mod->result += base_put(num, base, base_string);
}