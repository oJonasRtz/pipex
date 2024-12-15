/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:30:52 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/28 10:09:37 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

//  printf
int				ft_printf(const char *str, ...);

//  utils
int				ft_num_count(int n);
int				ft_itoa_base(unsigned long value, char *base);

//  'get' functions
int				ft_get_unsigned(unsigned int n);
int				ft_get_int(int n);
int				ft_get_percentage(void);
int				ft_get_char(char c);
int				ft_get_string(char *str);
unsigned long	ft_get_pointer(unsigned long p);

#endif
