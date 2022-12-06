/* print params
	* int i = -1;
	* printf("%s\n", p.file.infile);
	* printf("%s\n", p.file.outfile);
	* while (p.cmd != NULL)
	* {
	* 	i = -1;
	* 	printf("cmd: %s\n", p.cmd->cmd);
	* 	while (p.cmd->args[++i] != NULL)
	* 	{
	* 		printf("args: %s\t", p.cmd->args[i]);
	* 	}
	* 	printf("\n");
	* 	printf("path: %s\n", p.cmd->path);
	* 	printf("========================\n");
	* 	p.cmd = p.cmd->next;
	* 	sleep(1);
	* }
*/