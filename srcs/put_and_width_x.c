#include "../includes/ft_printf.h"

int	ft_wx(int len, char c)
{
	int res;

	res = len;
	while (len > 0)
	{
		write (1, &c, 1);
		len--;
	}
	return (res);
}

int base_put(t_flag *all_mod, long long num, int base)
{
	int i;
	char   *base_string;

	i = 0;
	base_string = all_mod->spc == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (num > 0) {
		write(1, &base_string[num % base], 1);
		num /= base;
		i++;
	}
	return(i);
}

int ft_sharp(t_flag *all_mod, int len)
{
	if (all_mod->spc == 'x')
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	if (all_mod->prc > len - 2)
		all_mod->res += ft_wx(all_mod->prc - len + 2, '0');
}
