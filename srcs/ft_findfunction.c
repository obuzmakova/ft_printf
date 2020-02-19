//
// Created by Magorian Leticia on 17/01/2020.
//

#include "../includes/ft_printf.h"

int ft_writespec(t_flag *all_mod, int check, long long nbr)
{
	if ((all_mod->specifier == 'x' || all_mod->specifier == 'X') && nbr != 0 && all_mod->flag_sh)
		return (2);
	return (0);
}

size_t count_for_len(long long nbr, int base, t_flag *all_mod)
{
   int count;
   int copy;
   int cpyspec;

   count = 0;
   cpyspec = nbr;
   copy = nbr;

   if (nbr < 0 || nbr == 0)
   	count += 1;
   nbr < 0 ? nbr *= -1 : nbr;
   while (nbr > 0)
   {
      nbr /= base;
      count += 1;
   }
   if (all_mod->flag_sh == '#')
   	if (copy != 0)
   		count += ft_writespec(all_mod, 0, cpyspec);
   return (count);
}

long long ft_findtype(va_list all_arg, t_flag *all_mod)
{
	if (all_mod->length == 2 && ft_memchr("di", (int)all_mod->specifier, 2))
		return((short)va_arg(all_arg, int));
	if (all_mod->length == 3 && ft_memchr("di", (int)all_mod->specifier, 2))
		return((long)va_arg(all_arg, long));
	if (all_mod->length == 4 && ft_memchr("di", (int)all_mod->specifier, 2))
		return((long long)va_arg(all_arg, long long));
	if (!all_mod->length && ft_memchr("oxXu", (int)all_mod->specifier, 4))
		return((unsigned int)va_arg(all_arg, unsigned int));
	if (all_mod->length == 1 && ft_memchr("oxXu", (int)all_mod->specifier, 4))
		return((unsigned short)va_arg(all_arg, int));
	if (all_mod->length == 2 && ft_memchr("oxXu", (int)all_mod->specifier, 4))
		return((unsigned char)va_arg(all_arg, int));
	if (all_mod->length == 3 && ft_memchr("oxXu", (int)all_mod->specifier, 4))
		return((unsigned long)va_arg(all_arg, unsigned long));
	if (all_mod->length == 4 && ft_memchr("oxXu", (int)all_mod->specifier, 4))
		return((unsigned long long)va_arg(all_arg, unsigned long long));
	else
		return(va_arg(all_arg, int));
}

void ft_putnum(t_flag *all_mod, long long num, int base, char *base_string)
{
	int dec;
	int curr;

	dec = 1;
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

void ft_findout(t_flag *all_mod, long long num, int base, int len)
{
	char   *base_string;

	base_string = all_mod->specifier == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (ft_memchr("oxXu", (int)all_mod->specifier, 4))
	{
		if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->flag_min != '-')
			all_mod->result += ft_spec_x(all_mod, num, len, base_string);
		else if (all_mod->precision > 0)
			all_mod->result += ft_spec_x(all_mod, num, len, base_string);
		ft_putnum(all_mod, num, base, base_string);
		if (all_mod->width > all_mod->precision && all_mod->width > len && all_mod->flag_min == '-')
			all_mod->result += ft_spec_x(all_mod, num, len, base_string);
	}
	else
		{
			while (num > 0) {
				write(1, &base_string[num % base], 1);
				num /= base;
			}
		}
}

void   *ft_itoa_base(va_list all_arg, t_flag *all_mod, int base)
{
	int       len;
	long long  nbr;
	char *sign;

    nbr = ft_findtype(all_arg, all_mod);
    sign = nbr >= 0 ? "+" : "-";
	len = count_for_len(nbr, base, all_mod);
	nbr < 0 ? nbr *= -1 : nbr;
    all_mod->result = all_mod->result + len;
    if (*sign == '-')
    	write(1, sign, 1);
	if (nbr == 0 && all_mod->width <= 0 && all_mod->precision <= 0)
	{
		write(1, "0", 1);
		return (&all_mod->result);
	}
    ft_findout(all_mod, nbr, base, len);
}

size_t ft_findfunction(va_list all_arg, t_flag *all_mod)
{
    if (all_mod->specifier == 'c')
        ft_spec_c(all_arg, all_mod);
    if (all_mod->specifier == 's')
        ft_spec_s(all_arg, all_mod);
    if ((all_mod->specifier == 'd') || (all_mod->specifier == 'i') || (all_mod->specifier == 'u'))
        ft_itoa_base(all_arg, all_mod, 10);
    if (all_mod->specifier == 'b')
        ft_itoa_base(all_arg, all_mod, 2);
    if (all_mod->specifier == 'o')
        ft_itoa_base(all_arg, all_mod, 8);
    if ((all_mod->specifier == 'X') || (all_mod->specifier == 'x') || (all_mod->specifier == 'p'))
        ft_itoa_base(all_arg, all_mod, 16);
	if (all_mod->specifier == '%')
		ft_percent(all_mod);
	if (all_mod->specifier == 'f')
		ft_spec_f(all_arg, all_mod);
	return(0);
}