# PIPEX - IPC Basics

<h3>Subject summary</h3>
<p>Create a program that imitates bash's pipes behaviour. For detailed information about the project refer to "subject.pdf".</p>  

### Usage  
```  
./pipex <infile> <cmd1> <cmd2> <outfile> || ./pipex_bonus <infile> <cmd1>, <cmd2>, ..., <cmdn> <outfile> || ./pipex_bonus heredoc <limiter> <infile> <cmd1>, <cmd2>, ..., <cmdn> <outfile>
```  
<h3>Key project takeaways</h3>

- Forks and child processes. What is a process. Zombie/Orphan processes.  
- I/O redirection.  
- Pipe architecture.  
- Communication between parent and child process.  
- Memory management.
- How a "heredoc" works. **(BONUS)**

### Side notes
In the final version I changed the way pipex works when a null 'envp' is passed. Instead of exiting with an error message, I returned the null 'envp' and let the program continue to run like bash would do. So that is a change needed to be made in this version for a fully functional pipex.

### Final grade
125/125
