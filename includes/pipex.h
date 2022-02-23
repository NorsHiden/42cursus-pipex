/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:18:03 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:18:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

/*____________MANDATORY____________*/

void	first_process(int *fdp, int infile, char **v, char **p);
void	second_process(int *fdp, char **v, char **p);
int		outfile_c(char *path);

/*______________TOOLS______________*/

char	**setup_cmd(char *str, char **p);
void	free_mem(char **str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		raise_error(char *error, char *name, unsigned char exit_code);

/*______________BONUS______________*/

char	*get_next_line(int fd);
void	run_process(int i, int c, char **v, char **p);
void	child_process(int	*fdp, char *fullcmd, char **p);
void	out_process(char *here_doc, char *fullcmd, char *outfile, char **p);

#endif