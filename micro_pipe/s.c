#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	if (str == NULL)
		return (cnt);
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	put_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	fatal_error(void)
{
	put_error("error: fatal\n");
	exit(1);
}

char	*ft_strcpy(char *str)
{
	char	*temp;
	int		idx;

	if (str == NULL)
		return (NULL);
	idx = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (idx + 1));
	if (temp == NULL)
		fatal_error();
	temp[idx] = '\0';
	idx = -1;
	while (str[++idx])
		temp[idx] = str[idx];
	return (temp);
}

char	**ft_strscpy_cmd(char **argv, int start, int end)
{
	char	**temp;
	int		idx;

	if (end == start)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (temp == NULL)
		fatal_error();
	idx = 0;
	while (start + idx < end)
	{
		temp[idx] = ft_strcpy(argv[start + idx]);
		idx++;
	}
	return (temp);
}

void	free_cmd(char **cmd)
{
	int	idx;

	if (cmd == NULL)
		return ;
	idx = -1;
	while (cmd[++idx])
		free(cmd[idx]);
	free(cmd);
}

void	execute_cd(char **argv, int start)
{
	int	idx;

	idx = start;
	while (argv[idx] && strcmp(argv[idx], "|") && strcmp(argv[idx], ";"))
		idx++;
	if (idx - start != 2)
		put_error("error: cd: bad arguments\n");
	else if (chdir(argv[start + 1]) < 0)
	{
		put_error("error: cd: cannot change directory to ");
		put_error(argv[start + 1]);
		put_error("\n");
	}
}

void	execute_cmd(char **cmd, int temp_fd, char **envp)
{
	if (dup2(temp_fd, STDIN_FILENO) < 0)
		fatal_error();
	close(temp_fd);
	execve(cmd[0], cmd, envp);
	put_error("error: cannot execute ");
	put_error(cmd[0]);
	put_error("\n");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		temp_fd;
	int		start;
	int		child;
	int		end;
	pid_t	pid;
	char	**cmd;
	int		pipe_fd[2];
	int		cmd_cnt;
	int		idx;

	(void)argc;
	start = 1;
	end = 1;
	cmd_cnt = 0;
	temp_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
		fatal_error();
	while (1)
	{
		if (argv[end] == NULL || !strcmp(argv[end], ";"))
		{
			if (argv[start] != NULL && !strcmp(argv[start], "cd"))
				execute_cd(argv, start);
			else if (start != end)
			{
				cmd = ft_strscpy_cmd(argv, start, end);
				cmd_cnt++;
				pid = fork();
				if (pid < 0)
					fatal_error();
				else if (pid == 0)
					execute_cmd(cmd, temp_fd, envp);
				else
				{
					close(temp_fd);
					idx = -1;
					while (++idx < cmd_cnt)
					{
						if (waitpid(0, &child, 0) < 0)
							fatal_error();
					}
					cmd_cnt = 0;
					temp_fd = dup(STDIN_FILENO);
					free_cmd(cmd);
					cmd = NULL;
					if (temp_fd < 0)
						fatal_error();
				}
			}
			start = end + 1;
			if (argv[end] == NULL)
				break ;
		}
		else if (!strcmp(argv[end], "|"))
		{
			if (!strcmp(argv[start], "cd"))
				execute_cd(argv, start);
			else
			{
				cmd_cnt++;
				if (pipe(pipe_fd) < 0)
					fatal_error();
				cmd = ft_strscpy_cmd(argv, start, end);
				pid = fork();
				if (pid < 0)
					fatal_error();
				else if (pid == 0)
				{
					close(pipe_fd[0]);
					if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
						fatal_error();
					close(pipe_fd[1]);
					execute_cmd(cmd, temp_fd, envp);
				}
				else
				{
					close(temp_fd);
					close(pipe_fd[1]);
					temp_fd = pipe_fd[0];
					free_cmd(cmd);
					cmd = NULL;
				}
			}
			start = end + 1;
		}
		end++;
	}
	close(temp_fd);
	if (child > 0)
		return (1);
	return (0);
}
