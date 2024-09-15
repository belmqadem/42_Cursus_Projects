# <div align="center">minishell</div>

## Introduction 🐚

**Minishell** is a simple Unix shell project developed in C. It emulates basic features of popular Unix shells like `bash`, implementing command execution, piping, environment variables, redirections, and more. This project is part of the [Insert School/University] curriculum and offers practical experience in understanding how a shell works from the ground up.

## Features ✨

- 🔄 **Basic shell prompt** with interactive input.
- 🚀 **Command execution** with relative and absolute paths.
- 🔧 **Built-in commands**:
  - `echo` (with `-n` option)
  - `cd` (change directory)
  - `pwd` (print current directory)
  - `export` (set environment variables)
  - `unset` (unset environment variables)
  - `env` (list environment variables)
  - `exit` (exit the shell)
- 🌍 **Environment variable expansion**.
- 🔗 **Piping** between commands (e.g., `ls | grep txt`).
- 📥 **Input/output redirection** (`>`, `>>`, `<`, `<<`).
- 🛠️ **Signal handling** (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`).
- 📜 **Heredoc** (`<<`) with custom implementation.

## Shell Parts Overview 🛠️

### Parsing Part 📝

The **parsing** part is responsible for processing the user’s input and converting it into a structured form, usually a set of tokens or commands that the shell can understand. It involves:

- **Lexical Analysis**: The input string is broken into tokens (e.g., command names, arguments, operators like `|`, `<`, `>`).
  
- **Syntax Parsing**: Tokens are analyzed to determine their function (command, argument, operator, etc.) and are grouped accordingly.

- **Environment Variable Expansion**: The shell replaces variables like `$HOME` with their corresponding values.

### Execution Part ⚙️

The **execution** part is where the parsed commands are executed. This part deals with:

- **Built-in Commands Execution**: The shell recognizes certain commands (like `cd`, `echo`) as built-in, and executes them internally.

- **External Command Execution**: For other commands, the shell locates the executable (using the `PATH` environment variable) and runs it via `execve()` or similar system calls.

- **Redirection Handling**: Redirection operators (e.g., `>`, `<`, `>>`, `<<`) are processed, and input/output is redirected as required.

- **Piping**: Handles connecting multiple commands through pipes (e.g., `command1 | command2`).

### Signal Handling 🚨

- **Ctrl+C**: Interrupts the current command and returns to the prompt.
- **Ctrl+D**: Exits the shell if the input is empty.
- **Ctrl+\**: Sends a quit signal to the current process.

## Resources 📚

- [📖 Bash Documentation](https://www.gnu.org/software/bash/manual/bash.html)
- [🌐 Unix Shell Introduction](https://www.geeksforgeeks.org/introduction-of-shell-programming/)








