/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:02:04 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 11:59:24 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# define MSG_FILE_NAME_MISSING "File name missing.\n"
# define MSG_TOO_MANY_ARGUMENTS "Too many arguments.\n"
# define MSG_CANNOT_READ_FILE "Cannot read file.\n"
# define ERR_FILE_NAME_MISSING 1
# define ERR_TOO_MANY_ARGUMENTS 2
# define ERR_CANNOT_READ_FILE 3
# define BUFF_SIZE 4096
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

void	error(char *error);
void	ft_putstr(char *str);
#endif
