# <div align=center> PIPEX </div>

## Overview 📝
pipex is a program that emulates the functionality of the shell pipe (|) in the Unix environment. It allows users to execute shell commands sequentially, with the output of one command serving as the input for the next. This project aims to provide a deeper understanding of the underlying Unix mechanisms by implementing them in a C program.

## External Functions 🔧
- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`
- `strerror`, `access`, `dup`, `dup2`
- `execve`, `exit`, `fork`, `pipe`
- `unlink`, `wait`, `waitpid`

## Usage 🚦
```bash
./pipex file1 cmd1 cmd2 file2
```

- <b>file1:</b> Input file whose content will be sent to the first command's standard input.
- <b>cmd1:</b> First command to be executed.
- <b>cmd2:</b> Second command to be executed.
- <b>file2:</b> Output file to which the final result will be written.

## Example
```c
./pipex infile "grep a1" "wc -w" outfile
```
This will behave like: $> <b> `< infile grep a1 | wc -w > outfile` </b>

## Bonus Features 🌟
- <b>Multiple Pipes:</b> Support for executing multiple commands sequentially.
```c
./pipex file1 "cmd1" "cmd2" "cmd3" ... "cmdn" file2
```
This will behave like: $> <b> `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2` </b>

- <b>Here Document Support:</b> Support for << and >> when the first parameter is "here_doc".
```c
./pipex here_doc LIMITER "cmd" "cmd1" file
```
This will behave like: $> <b> `cmd << LIMITER | cmd1 >> file1` </b>

## Installation 🛠️
1. Clone the repository:
```c
git clone https://github.com/yourusername/pipex.git
```
3. Navigate to the project directory:
```c
cd pipex
```
5. Compile the program:
```c
make
```

## Contributing 🤝
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.
