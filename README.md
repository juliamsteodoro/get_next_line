*This project has been created as part of the 42 curriculum by [jumoreir].*

<div align="center">

# GET_NEXT_LINE &nbsp;·&nbsp; <sub>by jumoreir</sub>

![C](https://img.shields.io/badge/C-language-blue?style=flat-square)
![42](https://img.shields.io/badge/42-school-black?style=flat-square)
![Norminette](https://img.shields.io/badge/norminette-passing-success?style=flat-square)
![Status](https://img.shields.io/badge/status-in--progress-yellow?style=flat-square)

*── Reading a file, one line at a time ──*

</div>

---

## Description

**get_next_line** is a function that reads and returns, one call at a time, the
next line from a given file descriptor — whether it points to a regular file,
standard input, or any other readable fd. It's one of the earliest 42 projects
to require a **static variable**, since the function needs to remember, between
calls, whatever was read past the end of the previous line.

Each call returns the next line, including the terminating `\n` (except when
the end of the file is reached without one). When there's nothing left to read,
or an error occurs, it returns `NULL`.

**Key learnings:**
- What a `static` variable is and why it's needed here
- Reading a stream in fixed-size chunks instead of all at once
- Manual, leak-free memory management across multiple function calls

<!-- TODO: mencione aqui se você implementou o bônus (múltiplos fds com uma
     única variável static) e qualquer decisão de projeto que valha destacar. -->

---

## Instructions

### Compilation

The internal read buffer size is set at compile time with `-D BUFFER_SIZE=n`.
The project must also compile without that flag, falling back to a default
value defined in the header.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c <your_main.c>
```

<!-- TODO: se tiver Makefile, documente as regras aqui, por exemplo:
make          # compiles get_next_line.c/.h into an object/library
make bonus    # compiles the multi-fd version (get_next_line_bonus.*)
make clean / fclean / re -->

### Usage

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

<!-- TODO: se implementou o bônus, adicione um exemplo com chamadas
     intercaladas em fds diferentes (ex: fd 3, depois fd 4, depois fd 3
     de novo), mostrando que o estado de cada um é preservado. -->

---

## Library

### Technical considerations

- Declaring global variables is forbidden.
- `lseek()` is forbidden.
- Using your own `libft` inside this project is forbidden.
- The returned line must include the `\n`, except at EOF without one.
- The function must read as little as possible per call — no full-file reads.

### Norminette

Same rules as every other 42 project — checked with the
[Norminette](https://github.com/42School/norminette).

### Functions from `get_next_line.h`

| Function | Description |
|---|---|
| `get_next_line` | Returns the next line read from a file descriptor |

<!-- TODO: liste aqui as funções auxiliares que você criou em
     get_next_line_utils.c, com uma descrição curta de cada uma
     (ex: extract_line, update_stash, join_free, etc.) -->

---

## Resources

### References

- [read(2) — man7.org](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C — cppreference.com](https://en.cppreference.com/w/c/language/storage_duration)
- [42 Norminette — GitHub](https://github.com/42School/norminette)

### AI usage
### AI usage

AI (Claude) was used throughout this project's development process for two
distinct purposes:

- **Norm debugging (`get_next_line.h`):** Claude was given the norminette
  error output for the header file and, instead of providing a corrected
  version directly, asked guiding questions about preprocessor nesting rules
  (e.g. comparing the already-passing `#ifndef GET_NEXT_LINE_H` block to the
  failing `BUFFER_SIZE` block) so I could work out the correct indentation
  pattern myself.

- **Algorithm structuring (`get_next_line.c`):** early in the conversation,
  Claude outlined one possible high-level structure for the function
  (the general read-loop / extract-line / update-stash approach commonly
  used to solve this project). At my request, it then switched to a fully
  Socratic mode for the rest of the design: instead of writing or completing
  any code, it asked targeted questions about the loop's stop condition, the
  static variable's initial state, EOF handling, and memory ownership between
  calls, so I could reason through and write the actual implementation
  myself.

- **Documentation:** Claude helped scaffold this README.md file (structure,
  section headers, and formatting) based on the project's `README
  Requirements` chapter and an existing README of mine (from another 42
  project) used as a style reference. The factual content specific to this
  project — function list, algorithm justification, and design choices —
  was written by me.

No AI-generated code was copied into `get_next_line.c`, `get_next_line.h`,
or `get_next_line_utils.c`. All function bodies, edge-case handling, and
memory management logic were designed and written independently.
---

## Algorithm

The implementation follows the classic incremental-read approach commonly
used to solve this project, structured around a single static buffer
(referred to here as the *stash*) that persists between successive calls.

**1. Static variable (the stash).** A `static char *` variable is used to
retain, between one call and the next, any characters that were already read
from the file descriptor but not yet returned as part of a line. Without it,
each call to `get_next_line` would start from a blank state and the data
read past the end of the previous line would be lost, making it impossible
to reconstruct the file's content correctly across multiple calls.

**2. Read loop and stop condition.** Data is read from the file descriptor
in chunks of `BUFFER_SIZE` bytes at a time, appending each chunk to the
stash, rather than reading the entire file in a single pass. The loop stops
under two conditions: as soon as the stash contains a newline character, or
when `read()` returns that there is nothing left to read from the file
descriptor (end of file).

**3. Locating the end of the line.** The boundary of the line to be returned
is determined by searching the stash for the `\n` character. Its position
marks where the current line ends and where the remaining, unread content
begins.

**4. Preserving the remainder for the next call.** Once a line has been
extracted, the content located after the `\n` is copied into a new buffer.
The previous stash is then freed, and the static variable is reassigned to
point to this new buffer, ensuring that only the unread portion of the data
is retained for the next call, with no memory leaks between calls.
