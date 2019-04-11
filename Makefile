##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## Builds the binary
##

override CFLAGS		+=	-W -Wall -Wextra -Werror
override CPPFLAGS	=	-I ./include
override LDFLAGS	+=

CC		=	gcc
LD		=	$(CC)

BINARY		=	mysh
BINARY_TEST	=	unit_tests

SRCTEST		=	tests/tests_char_toolbox.c	\
			tests/tests_commands_creation.c	\
			tests/tests_exec_list.c		\
			tests/tests_file_toolbox.c	\
			tests/tests_get_next_line.c	\
			tests/tests_get_word.c		\
			tests/tests_line_parsing.c	\
			tests/tests_list_toolbox.c	\
			tests/tests_list_validity.c	\
			tests/tests_prompt_display.c	\
			tests/tests_string_toolbox.c

SRCMAIN		=	src/main.c

SRC		=	src/builtin/cd.c			\
			src/builtin/env.c			\
			src/builtin/exit.c			\
			src/builtin/setenv.c			\
			src/builtin/unsetenv.c			\
			src/env_handling/env_toolbox.c		\
			src/env_handling/path_toolbox.c		\
			src/env_handling/var_toolbox.c		\
			src/execution/commands_handling.c	\
			src/execution/list_handling.c		\
			src/execution/list_validity.c		\
			src/execution/pipe_sequence_handling.c	\
			src/execution/redirs_creation.c		\
			src/prompt/commands_execution.c		\
			src/prompt/input_parsing.c		\
			src/prompt/input_toolbox.c		\
			src/prompt/prompt_display.c		\
			src/prompt/status_toolbox.c		\
			src/tokens/list_toolbox.c		\
			src/tokens/token_creation.c		\
			src/tokens/word_toolbox.c		\
			src/utilities/char_toolbox.c		\
			src/utilities/file_toolbox.c		\
			src/utilities/get_next_line.c		\
			src/utilities/nbr_toolbox.c		\
			src/utilities/output_messages.c		\
			src/utilities/str_display.c		\
			src/utilities/string_toolbox.c

OBJTEST		=	$(SRCTEST:.c=.o)

OBJMAIN		=	$(SRCMAIN:.c=.o)

OBJ		=	$(SRC:.c=.o)

$(BINARY):	$(OBJ) $(OBJMAIN)
	$(LD) -o $@ $^ $(LDFLAGS)

$(BINARY_TEST):	$(OBJ) $(OBJTEST)
	$(LD) -o $@ $^ $(LDFLAGS)

all:		$(BINARY)

clean:
	@echo Removing mysh temporary files
	@rm -f $(OBJ) $(OBJMAIN) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
	@rm -f $(OBJTEST) $(OBJTEST:.o=.gcno) $(OBJTEST:.o=.gcda)

fclean:		clean
	@echo Removing mysh binary
	@rm -f $(BINARY)

tests_run:	LDFLAGS	+=	-lcriterion --coverage
tests_run:	CFLAGS	+=	--coverage
tests_run:	clean $(BINARY_TEST)
	./$(BINARY_TEST)

re:		fclean all

.PHONY:		all clean fclean re
