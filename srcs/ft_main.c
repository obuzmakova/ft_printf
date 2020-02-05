/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/02/05 17:56:51 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	//ft_printf("");
	//ft_printf("%+#- 5.8099ld");
	//printf("%0- 5.89d");
	//ft_printf("toto%% %#0-+ 12.74llc%-+hs%34.6d %%", 'm' , "komputer", 7);
	//printf("res = %i\n", ft_printf); // проверка
	//ft_printf("hello, %s.", NULL);
	//printf("hello, %s.", NULL);
	//printf("NULL");
	//ft_printf("%s", NULL);

	ft_printf("our_printf = %8.5x", 34);
	printf("original printf = %8.5x", 34);
	//ft_printf("my %p", "4jfyjyj");
	//ft_printf("%-10.5s", "hello");
	//ft_printf("hello, %s.", "gavin");
	//ft_printf("toto%- 846.9ld, tata %+7.5hs, tutu", 689, 12);
	return (0);
}

