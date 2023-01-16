# Pipex 42 Network Project
### Introduction

The pipex 42 network project is a networking project that utilizes the standard library functions for creating and managing pipes. The project is designed to demonstrate the capabilities of these functions, and is intended for use in educational and research contexts.
Library Functions


Implementation

The pipex 42 network project makes use of these functions to create and manage pipes between different processes. The project demonstrates the use of pipes to create a simple network of processes that communicate with one another.

Usage
compile the project by running `make all` or `make bonus`
run the project with 
```bash
./pipex infile cmd1 cmd2 outfile
```
it should behave like the built in bash pipes and redirections `< infile cmd1 | cmd2 > outfile`

For the pipeline or the heredoc you can compile your code with the following command `make bonus`
```bash
/.pipex here_doc LIMITER cmd1 cmd2 file
```
it should behave like `cmd1 << LIMITER | cmd2 >> file`
```bash
./pipex infile "cmd1" "cmd2" "cmd3" "cmdn" outfile
```
it should behave like `< infile cmd1 | cmd2 | cmd3 | cmdn > outfile`

The pipex 42 network project makes use of several functions from the standard library, including the following:

    pipe(): This function is used to create a new pipe and return two file descriptor that can be used to read and write data to the pipe.

    dup2(): This function is used to replace one file descriptor with another. It takes as arguments the file descriptor to be replaced and the file descriptor to replace it with.

    execve() : This function is used to execute a file, the arguments passed to execve are the path of the file, array of arguments and array of environment variables

    close(): This function is used to close a file descriptor and release any resources associated with it. It takes as an argument the file descriptor of the pipe to be closed.

    perror(): This function is used to print a error message on the standard error output. It takes as an argument a string which is the error message.

    waitpid(): This function is used to wait for a child process to terminate and return its exit status. It takes as arguments the process id of the child process, a pointer to the status variable, and options for controlling the wait.

    exit(): This function is used to terminate the calling process. It takes as an argument the exit status of the process.

    unlink(): This function is used to delete a file or a symbolic link. It takes as an argument the path of the file or the symbolic link to be deleted.

    fork(): This function is used to create a new child process. It returns the process ID of the child process in the parent and 0 in the child process.
    
    access(): This function is used to check the accessibility of a file or a directory. It takes as arguments the path of the file or directory and the type of access needed.
    
    strerror(): This function is used to return a string describing the error code passed as an argument.
    
    malloc(): This function is used to dynamically allocate memory at runtime. It takes as an argument the number of bytes to be allocated.
    
    free(): This function is used to release memory that was previously allocated using malloc. It takes as an argument a pointer to the memory to be released.

    open(): This function is used to open a file and return a file descriptor that can be used to read and write to the file.

    read(): This function is used to read data from a file or a device. It takes as arguments the file descriptor, a pointer to a buffer where the read data will be stored, and the number of bytes to be read.


### License

This project is licensed under the MIT License.

### Contributions

Feel free to contribute and submit pull requests.

### Disclaimer
This project is for educational and research purposes only and should not be used as a starting point for a production-ready solution. The project is not intended to provide a comprehensive or fully-featured solution and should not be used as a dependency in any production-level projects. The project is intended to demonstrate the use of certain functions and techniques, and should be used as a reference or learning tool. It is the user's responsibility to thoroughly evaluate the suitability of any code used in production.
