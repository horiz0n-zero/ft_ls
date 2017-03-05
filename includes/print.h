/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:01:06 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 03:11:44 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

char	*ft_number(char *buffy, char *ptr, va_list *args);
char	*ft_clean(char * const buffer);
char	*ft_star(char *buf, char *ptr, va_list *args);
#endif
