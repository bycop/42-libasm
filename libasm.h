/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:01:32 by sfournio          #+#    #+#             */
/*   Updated: 2021/03/09 12:59:37 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/*
**		type	ft_function(rdi, rsi, rdx);
*/

ssize_t	ft_write(int fildes, const char *buf, ssize_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *first, const char *second);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);

#endif
