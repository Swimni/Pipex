/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:33:44 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/15 01:25:49 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	int	fd[2];
}		t_pipex;

typedef struct s_exec
{
	int		i;
	int		n_cmd;
	int		infile;
	int		outfile;
	int		**pipes;
	char	**argv;
	char	**envp;
}	t_exec;

void	execute_cmd(char *cmd, char **envp, t_pipex *px);
void	free_split(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_path_from_envp(char **envp);
char	*get_cmd_path(char *cmd, char **envp);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
int		count_words(char const *s, char c);
int		len_word(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_split_cmd(const char *cmd);
int		is_quote(char c);
int		arg_len(const char *s);
int		count_args(const char *cmd);
char	*copy_arg(const char *src, int len);
size_t	ft_strlen(char *str);
void	ft_strcat(char *s1, char *s2, char *join);
char	*ft_strjoin(char *s1, char *s2);
void	free_pipes(int **pipes, int count);
char	*get_cmd(char **path, char *cmd, int i);
char	**split_cmd_while(const char *cmd, char **argv);
void	ft_putstr_fd(char *s, int fd);
int		check_argc(int argc, char **argv);
int		check_infile(int infile);
int		check_outfile(int outfile, int infile);
int		check_pid(pid_t pid, int fd[2], int infile, int outfile);
void	exec_pid1(t_pipex *px, char **argv, char **envp);
void	exec_pid2(t_pipex *px, char **argv, char **envp);
void	close_all(int fd[2], int infile, int outfile);
void	wait_all(pid_t pid1, pid_t pid2);
void	check_acces_outfile(int argc, char **argv, int infile);

int		while_pipe(int **pipes, int n_cmd);
//void	while_fork(char **envp, int argc, int **pipes, char **argv);
void	while_fork(t_exec *ex);
void	first_cmd(int infile, int **pipes, int i);
void	last_cmd(int outfile, int **pipes, int i);
void	middle_cmd(int **pipes, int i);
void	close_all_bonus(int n_cmd, int **pipes, int j);
int		infile_outfile(int *infile, int *outfile, int argc, char **argv);
void	close_both(int infile, int outfile);
void	close_free_pipes(int **pipes, int n_cmd);
void	close_everything(int infile, int outfile, int n_cmd, int **pipes);
void	check_arg(char **args);
void	close_all_fds(t_pipex *px);
void	execute_cmd_bonus(char *cmd, t_exec *ex);
void	check_acces_infile(char **argv);
void	check_acces_outfile_bonus(int argc, char **argv, t_exec *ex);
int		ft_strchr(char *str, char c);
char	*resolve_cmd(char *cmd, char **envp);
char	*ft_strdup(char *s);

void	setup_cmd(t_exec *ex);
void	exec_child(t_exec *ex);
void	init_exec(t_exec *ex, int argc, char **argv, char **envp);
void	free_exec(t_exec *ex);
void	free_child_and_exit(t_exec *ex, int code);
void	check_acces_infile_bonus(char **argv);

void	ft_strcat3(char *s1, char *s2, char *s3, char *join);
char	*ft_strjoin3(char *s1, char *s2, char *s3);

void	close_free_pipes(int **pipes, int n_cmd);
void	check_arg_bonus(char **args, t_exec *ex);

#endif