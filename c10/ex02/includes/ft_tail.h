/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:54:34 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 18:19:01 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# define MSG_CANNOT_READ_FILE ": No such file or directory"
# define MSG_ILLEGAL_OFFSET "illegal offset -- "
# define BUFF_SIZE 4096
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	error(char *error);
void	ft_putstr(char *str);
int		ft_is_numeric(char *str);
void	print_separator(char *file_name, int index, int start, int last_error);
void	read_stdin(int tail);
int		has_files_after(int ac, int size, char *pn, char **av);
int		verif(int *size, int *index2, char **av, int ac);
int		display_error(char *file_name, char *message, int dm, char *pn);
#endif
