CC = cc
CFLAGS = -Wall -Wextra -Werror 
C_NAME = client
S_NAME = server
SRCDIR = src
OBJDIR = obj
INCDIR = include

C_SRC = src/client.c
S_SRC = src/server.c

C_OBJ = $(addprefix $(OBJDIR)/,$(notdir $(C_SRC:%.c=%.o)))
S_OBJ = $(addprefix $(OBJDIR)/,$(notdir $(S_SRC:%.c=%.o)))

all: $(OBJDIR) $(S_NAME) $(C_NAME)

$(OBJDIR):
	mkdir obj

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(@) -c $(<)

$(S_NAME): $(S_OBJ)
	$(CC) -o $(S_NAME) $(S_OBJ) $(LIB)

$(C_NAME): $(C_OBJ)
	$(CC) -o $(C_NAME) $(C_OBJ) $(LIB)

clean:
	$(RM)r $(OBJDIR)

fclean: clean
	$(RM) $(S_NAME) $(C_NAME)

re: fclean all