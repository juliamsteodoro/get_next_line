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

| Helper | Description |
|---|---|
| `TODO` | `TODO` |

### Bonus — Multiple file descriptors

<!-- TODO: se fez o bônus, explique brevemente como uma única variável
     static consegue gerenciar o estado de vários fds ao mesmo tempo
     (ex: array de ponteiros indexado pelo próprio fd). -->

---

## Resources

### References

- [read(2) — man7.org](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C — cppreference.com](https://en.cppreference.com/w/c/language/storage_duration)
- [42 Norminette — GitHub](https://github.com/42School/norminette)

### AI usage

<!-- TODO: descreva honestamente. Ex: "AI (Claude) was used in a Socratic
     mode only — it asked guiding questions about the reading loop, the
     stash/stop condition, and norminette indentation rules, without
     writing get_next_line.c/.h code directly. All implementation
     decisions and code were written by me." -->

---

## Algorithm

<!-- Seção obrigatória pelo subject — precisa ser a SUA explicação e
     justificativa. Roteiro de perguntas pra te ajudar a escrever:

     1. Por que usar uma variável static para guardar o "resto" (stash)
        ainda não retornado? O que quebraria sem ela entre chamadas?
     2. Qual é a condição exata que faz o loop de read() parar? Por que
        ler aos poucos (BUFFER_SIZE) em vez do arquivo inteiro de uma vez?
     3. Como você localiza o fim da linha dentro do stash acumulado?
     4. Como o restante do buffer (depois do '\n') é preservado pra
        a próxima chamada, sem vazar memória?
     5. Como você trata EOF sem '\n' final, fd inválido e erro de read()?
     6. (Bônus, se aplicável) Como uma única variável static gerencia
        vários fds sem misturar o estado de cada um? -->