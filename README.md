# Shell Project

This project is a simple shell implementation in C programming language, aiming to provide a command-line interface where users can interact with the system by executing commands. It supports basic functionalities such as executing commands, handling environment variables, and managing paths.

![gif](media/programming.gif)

## Features

- **Command Execution**: Users can execute various commands supported by the underlying operating system.
- **Environment Variables**: The shell supports environment variables and allows users to print them using the `env` command.
- **Path Resolution**: It can find the location of executable files specified by users in the PATH environment variable.

## File Structure

The project is organized into several C source files:

- **`shell.c`**: Contains the main functionality and implementation of the shell.
- **`prompt_string.c`**: Provides functions related to printing the prompt string.
- **`print_env.c`**: Contains functions for printing environment variables.
- **`init_path.c`**: Functions for initializing and freeing the PATH variable.
- **`getcommand.c`**: Handles user input and parsing commands.
- **`find_file.c`**: Implements finding executable files in the PATH.
- **`exec_comm.c`**: Functions for executing commands.
- **`_strtok.c`**: Custom implementation of the `strtok` function for tokenizing strings.

## Usage

To compile the shell, run:

```
gcc -Wall -Werror -pedantic -Wextra *.c -o shell
```

Then, execute the compiled shell binary:

```
./shell
```

Once the shell is running, you can type commands just like in a regular terminal.

## Future Improvements

- **Error Handling**: Enhance error handling to provide more informative error messages to users.
- **Built-in Commands**: Implement additional built-in commands such as cd, history, etc.
- **Interactive Features**: Add support for interactive features like command history, auto-completion, and customizable prompt.

## Contribution
Contributions to this project are welcome. If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.
