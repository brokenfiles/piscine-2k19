/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:05:24 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 16:01:58 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define MSG_FILE_NAME_MISSING "File name missing.\n"
# define MSG_CANNOT_READ_FILE ": No such file or directory\n"
# define ERR_FILE_NAME_MISSING 1
# define BUFF_SIZE 9064
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

void	error(char *error);
void	ft_putstr(char *str);
#endif
