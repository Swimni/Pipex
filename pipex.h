/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:17:23 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 16:06:30 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	char	**cmds;
	char	**envp;
	int		cmd_count;
	int		(*pipes)[2];
	int		infile_fd;
	int		outfile_fd;
}	t_pipex;

//create_pipe_chain.c
void	child_process(int i, t_pipex *px);
int		close_all_pipes(int pipes[][2], int count);
void	wait_all(int count);
pid_t	ft_fork(void);
void	create_pipe_chain(t_pipex *px);

//exec_cmd.c
void	exec_cmd(char *cmd, char **envp);

//ft_split.c
int		count_words(char const *s, char c);
void	free_all(char **tab, int i);
int		len_word(char const *s, char c);
char	**ft_split(char const *s, char c);

// gnl.c
int		linefinished(char *str);
char	*readfile(int fd, char **stash);
char	*get_next_line(int fd);
char	*clean(char **stash);
char	*ft_strdup(const char *s);
void	ft_switchup(char **stash, char **buffer);
int		tchek(int fd, char **stash);

//here_doc.c
void	read_here_doc_input(char *limiter, int write_fd);
int		open_here_doc_outfile(char *filename);
void	init_here_doc(t_pipex *px, char **argv, int argc, char **envp);

//libft.c
void	free_split(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *str);

//path_utls.c
char	*find_cmd_path(char *cmd, char **envp);
char	*join_and_check(char *dir, char *cmd);

//pipex.c
int		open_infile(char *filename);
int		open_outfile(char *filename);
void	init_pipex(t_pipex *px, char **argv, int argc, char **envp);

//utlis.c
void	error_exit(const char *msg);
void	fork_all(t_pipex *px);
int		create_pipes(int pipes[][2], int count);

#endif