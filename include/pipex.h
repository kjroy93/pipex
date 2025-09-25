/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:23:23 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/25 16:02:31 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

typedef struct s_cmd
{
	char			**argv;
	int				index;
	struct s_cmd	*next;
}	t_cmd;

/**
 * @struct s_pipex
 * @brief Main structure for managing pipeline execution.
 *
 * This structure contains all relevant information for the
 * pipex program, including input/output files, commands,
 * file descriptors, child processes, and environment variables.
 */
typedef struct s_pipex
{
    char    *outfile;   /**< Output file path. */
    char    *infile;    /**< Input file path. */
    char    **envp;     /**< Environment variables from main. */
    int     outfile_fd; /**< File descriptor for the output file. */
    int     infile_fd;  /**< File descriptor for the input file. */
    int     heredoc;    /**< Flag indicating if here-document mode is used. */
    int     n_cmds;     /**< Number of commands in the pipeline. */
    t_cmd   *cmds;      /**< Pointer to the head of the command list. */
    pid_t   *pids;      /**< Array of child process IDs. */
}   t_pipex;

// ----------------- Structure ----------------------

/**
 * @brief Prepares a new node for the command list.
 *
 * @param cmd_str Command string.
 * @param i Index of the command in the pipeline.
 * @return Pointer to the newly created t_cmd node.
 */
t_cmd	*prepare_node(char *cmd_str, int i);

/**
 * @brief Adds a new node at the end of the list.
 *
 * @param lst Pointer to the head of the node list.
 * @param new Node to be added.
 */
void	cmd_add_back(t_cmd **lst, t_cmd *new);

/**
 * @brief Frees all nodes in the list.
 *
 * @param lst Pointer to the head of the node list.
 */
void	cmd_free(t_cmd **lst);

/**
 * @brief Frees a dynamically allocated matrix of strings.
 *
 * @param matrix Matrix to be freed.
 */
void	free_matrix(char **matrix);

/**
 * @brief Processes commands from the arguments and stores them in the structure.
 *
 * @param argc Number of arguments from main.
 * @param argv Arguments from main.
 * @param data Main structure containing node content.
 */
void	get_commands(int argc, char **argv, t_pipex *data);

/**
 * @brief Splits a command string into its components, handling inner quotes.
 *
 * Example of command:
 * @code
 * "grep 'hello world'"
 * argv[0] = grep
 * argv[1] = hello
 * argv[2] = world
 * @endcode
 *
 * The resulting array will be stored in a t_cmd node.
 *
 * @param s Command string to split.
 * @return Double pointer containing the command components.
 */
char	**split_with_quotes(const char *s);

// ------------------ Error Management ----------------------

/**
 * @brief Prints an error message and exits the program.
 *
 * @param message Message to display.
 */
void	perror_exit(char *message);

/**
 * @brief Frees allocated resources and prints an error before exiting.
 *
 * @param data Main structure.
 * @param cmd Node to free.
 * @param path Path string to free (if any).
 */
void	perror_free(t_pipex *data, t_cmd *cmd, char *path);

// ------------------ Utilities ---------------------------

/**
 * @brief Determines the correct executable path for a command.
 *
 * Example:
 * @code
 * ./pipex infile cmd1 cmd2 outfile
 * cmd = cat
 * if (access(cmd, X_OK) == 0) -> correct
 * else if (access("/bin/cat", X_OK) == 0) -> correct
 * @endcode
 *
 * @param cmd Command name or path.
 * @param envp Environment variables containing PATH.
 * @return Correct full path to the executable, or NULL if not found.
 */
char	*define_path(char *cmd, char **envp);

/**
 * @brief Waits for multiple child processes to finish.
 *
 * @param pids Array of child process IDs.
 * @param n Number of child processes.
 * @return Status code of the last finished child process.
 */
int		special_wait(pid_t *pids, int n);

/**
 * @brief Processes commands when using here-document mode.
 *
 * @param argc Number of arguments from main.
 * @param argv Arguments from main.
 * @param data Main structure containing node content.
 */
void	get_commands_here_doc(int argc, char **argv, t_pipex *data);

/**
 * @brief Redirects the standard input (stdin) to a given file descriptor.
 *
 * Typically used to redirect input from a file.
 *
 * @param fd File descriptor to redirect stdin to.
 */
void	redirect_infile(int fd);

/**
 * @brief Redirects the standard output (stdout) to a given file descriptor.
 *
 * Typically used to redirect output to a file.
 *
 * @param fd File descriptor to redirect stdout to.
 */
void	redirect_outfile(int fd);

/**
 * @brief Redirects the standard input (stdin) to read from a pipe.
 *
 * Used when connecting the output of a previous command to this command.
 *
 * @param read_fd Read end of the pipe.
 */
void	redirect_pipe_in(int read_fd);

/**
 * @brief Redirects the standard output (stdout) to write to a pipe.
 *
 * Used when connecting this command’s output to the next command in the pipeline.
 *
 * @param write_fd Write end of the pipe.
 */
void	redirect_pipe_out(int write_fd);

/**
 * @brief Opens input and output files for the pipeline.
 *
 * Opens the files specified in the t_pipex structure and stores
 * their file descriptors in infile_fd and outfile_fd. Handles
 * errors if files cannot be opened.
 *
 * @param data Pointer to the main t_pipex structure.
 * @return 0 on success, -1 on failure.
 */
int	open_files(t_pipex *data);

/**
 * @brief Closes the input and output file descriptors in the parent process.
 *
 * Ensures that file descriptors are properly closed after pipeline
 * execution to avoid resource leaks.
 *
 * @param data Pointer to the main t_pipex structure.
 */
void	close_fd_parent(t_pipex *data);

// ---------------------- Execution -----------------------

/**
 * @brief Executes a command node.
 *
 * Handles redirections, forks, and executes the command.
 *
 * @param cmd Pointer to the command node.
 * @param data Main structure containing all relevant data.
 * @param envp Environment variables for execve.
 */
void	execute(t_cmd *cmd, t_pipex *data, char **envp);

/**
 * @brief Executes the pipeline using parent and child processes.
 *
 * @param data Main structure containing command nodes and file descriptors.
 * @param envp Environment variables for execution.
 * @return Exit status of the pipeline.
 */
int		pater_familias(t_pipex *data, char **envp);

/**
 * @brief Executes the pipeline in bonus mode (here_doc or extended features).
 *
 * @param data Main structure containing command nodes and file descriptors.
 * @return Exit status of the pipeline.
 */
int		pater_familias_bonus(t_pipex *data);

/**
 * @brief Executes the first child process in bonus mode.
 *
 * Handles input redirection and writes to the first pipe.
 *
 * @param data Main structure containing command nodes and file descriptors.
 * @param cmd Pointer to the first command node.
 * @param fd Pipe file descriptors array [read, write].
 */
void	first_child_bonus(t_pipex *data, t_cmd *cmd, int fd[2]);

/**
 * @brief Executes a middle child process in bonus mode.
 *
 * Handles reading from the previous pipe and writing to the next pipe.
 *
 * @param data Main structure containing command nodes and file descriptors.
 * @param fd Pipe file descriptors array [read, write].
 * @param fd_in File descriptor for input from the previous command.
 */
void	mid_child_bonus(t_pipex *data, int fd[2], int *fd_in);

/**
 * @brief Executes the last child process in bonus mode.
 *
 * Handles reading from the previous pipe and writing to the output file.
 *
 * @param data Main structure containing command nodes and file descriptors.
 * @param fd_in File descriptor for input from the previous command.
 */
void	last_child_bonus(t_pipex *data, int *fd_in);

#endif
