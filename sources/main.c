/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:01:10 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 18:11:40 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
	{
		if (ft_check_file(argv[1]) == 0)
		{
			ft_printf("Error map isn't .ber");
			return (ft_printf(" format or doesn't exist\n"));
		}
		if (ft_create_tab(argv[1]) == 0)
			return (0);
		return (1);
	}
}
