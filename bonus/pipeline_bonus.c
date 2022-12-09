#include "pipex_bonus.h"

static void	open_files(t_params *p)
{
	p->file.infd = open(p->file.infile, O_RDONLY);
	if (p->file.infd == -1)
		exit_failure(errno, 1);
	p->file.outfd = open(p->file.outfile, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (p->file.outfd == -1)
		exit_failure(errno, 1);
}

void	display(void *node)
{
	t_cmd *tmp = node;
	ft_fprintf(1, "cmd: %s\n", tmp->cmd);
	ft_fprintf(1, "args: {%s, %s}\n", tmp->args[0], tmp->args[1]);
	ft_fprintf(1, "path: %s\n", tmp->path);
	ft_putstr_fd("=====================\n", 1);
}

t_list	*parse_commands(t_params *p)
{
	t_list	*cmds;
	t_cmd	*node;
	int		i;

	i = 1;
	cmds = NULL;
	node = malloc(sizeof(node));
	if (!node)
		return (NULL);
	while (++i < p->main.ac - 1)
	{
		node->cmd = ft_strdup(p->main.av[i]);
		node->args = ft_split(p->main.av[i], ' ');
		node->path = get_path(node->args[0], p->main.envp);
		ft_lstadd_back(&cmds, ft_lstnew(ft_strdup_cmd(node)));
		free_cmd_node(node);
	}
	return (cmds);
}

static void	parse_pipeline(int argc, char **argv, char **envp, t_params *p)
{
	pid_t	*arr_of_pids;
	int		**pipelines;
	int		i;

	i = -1;
	p->main.ac = argc;
	p->main.av = argv;
	p->main.envp = envp;
	p->ncmd = argc - 3;
	p->file.infile = argv[1];
	p->file.outfile = argv[argc - 1];
	p->cmds = parse_commands(p);
	p->arr_of_pids = malloc(sizeof(pid_t) * (p->ncmd + 1));
	if (!p->arr_of_pids)
		return ;
	p->pipelines = malloc(sizeof(int *) * (p->ncmd));
	if (!p->pipelines)
		return ;
	while (++i < p->ncmd)
	{
		p->pipelines[i] = malloc(sizeof(int) * 2);
		if (!p->pipelines[i])
			// return (free_tab(p->pipelines));
			return ;
		if (pipe(p->pipelines[i]) == -1)
			exit_failure(errno, 1);
	}	
}

void	pipeline(int argc, char **argv, char **envp)
{
	t_params	p;
	t_cmd		*cmd;
	int			i;

	if (argc < 5)
		return ;
	i = 1;
	parse_pipeline(argc, argv, envp, &p);

	exec_first_cmd(&p);

	exec_middle_cmd(&p);

	ft_lstlast(p.cmds);
	exec_last_cmd(&p);

	at_exit_pipeline(&p);
}







	// ft_lstiter(p.cmds, &display);