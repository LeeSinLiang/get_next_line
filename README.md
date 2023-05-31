<h1 align="center">Get Next Line</h1>

<p align="center">
	<img src="https://img.shields.io/github/license/LeeSinLiang/get_next_line.svg?style=flat-square" alt="license"/>
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/LeeSinLiang/get_next_line?color=blue&style=flat-square" />
</p>

`get_next_line` is a function that allows you to read content line by line from a file descriptor in C programming language. It reads a line from the specified file descriptor until a newline character ('\n') is encountered or the end of file (EOF) is reached.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Function Signature](#function-signature)
- [Return Value](#return-value)
- [Error Handling](#error-handling)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The `get_next_line` function is a useful tool when you need to read a file line by line, especially when dealing with large files or input from the standard input. It eliminates the need to read the entire file into memory, allowing you to process the file content incrementally. Furthermore, it can manage multiple file descriptors at the same time.

## Installation

To use the `get_next_line` function, follow these steps:

1. Download the source files for `get_next_line`: `git clone https://github.com/LeeSinLiang/get_next_line.git`.
2. Include the header file in your C program: `#include "get_next_line.h"`.
3. Compile your program along with the `get_next_line` source files using your preferred C compiler.

## Usage

The `get_next_line` function is called in a loop until it returns a value indicating the end of file or an error. The function prototype is as follows:

```c
char *get_next_line(int fd);
```
- `fd`: The file descriptor from which to read the input.

### Return Value

The `get_next_line` function returns the following values:

- `<line of file>` if a line has been read successfully.
- `(null)` if an error occurred or if the end of file has been reached.

### Error Handling

The `get_next_line` function handles various error cases, including:

- Invalid file descriptor.
- Memory allocation failures.
- Read errors.

## Example

Here's an example usage of the `get_next_line` function (provided in `main.c` file):

```c
#include <stdio.h>
#include <stdbool.h>

bool	gnl(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	if (buffer == NULL)
		return (true);
	printf("%s", buffer);
	free(buffer);
	return (false);
}

int	main(void)
{
	int	n;
	int	fd;

	n = 0;
	fd = open("get_next_line.c", O_RDWR);
	while (gnl(fd) == false)
		n++;
	printf("\n--------------END OF LINE READING--------------\n");
	printf("\nN Lines: %d\n", n);
	return (0);
}

```
Run with `cc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<insert buffer size of choice here>`.

In this example, the `get_next_line` function is called in a loop until the end of file is reached or an error occurs. Each line is processed within the loop, and the memory allocated for each line is freed.

## Contributing

Contributions to `get_next_line` are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.

## License

This project is licensed under the [MIT License](LICENSE).
