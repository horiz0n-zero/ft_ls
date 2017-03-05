/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:01:06 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 19:57:50 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# define BUFFY 8096

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

char	*ft_push_str(char *const buffer, char *progress, va_list *args);

char	*ft_number(char *const buffer, char *ptr, va_list *args);
char	*ft_stc_number(int number);

char	*ft_clean(char * const buffer);

char	*ft_nstar(char *const buffer, char *ptr, va_list *args, int n);
char	*ft_star(char *const buffer, char *ptr, va_list *args);

#endif
