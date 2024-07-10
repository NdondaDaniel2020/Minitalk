/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:50:34 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/09 15:49:28 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

static int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(unsigned char *str, int str_base)
{
	int i = 0;
	int	s = 1;
	int r = 0;

	while (str[i] < 32)
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_valid(str[i]))
	{
		r = value_of(str[i]) + (r * str_base);
		i++;
	}
	return (r*s);
}
