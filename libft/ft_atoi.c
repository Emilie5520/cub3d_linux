/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:26:05 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 10:45:33 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	char	*s;

	i = 0;
	sign = 1;
	result = 0;
	s = (char*)str;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r'
			|| s[i] == '\v' || s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result * sign);
}
