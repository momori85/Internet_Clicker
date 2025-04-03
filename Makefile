
CC=cc

NAME=monapp-Internet-Clicker

SRC = main.c load_texture.c ft_find_texture.c list_create.c loading_loop.c init_rect_for_texture.c init_text.c ft_process_screens.c ft_free.c

RM=rm -f

OBJ = $(SRC:.c=.o)

CFLAGS= -Wall -Wextra -Werror -I$(HOME)/.local/include -g

LDLIBS= -L$(HOME)/.local/lib -lSDL2_mixer -lSDL2 -lSDL2_ttf -lSDL2_image

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Variables
DESKTOP_INSTALL_PATH = ~/.local/share/applications
ICON_INSTALL_PATH = ~/.local/share/icons/hicolor/256x256/apps

# Assurez-vous que les répertoires existent
$(DESKTOP_INSTALL_PATH):
	mkdir -p $(DESKTOP_INSTALL_PATH)

$(ICON_INSTALL_PATH):
	mkdir -p $(ICON_INSTALL_PATH)

# Règle principale pour installer l'application et son icône
APP_NAME = monapp-Internet-Clicker
EXEC_PATH = $(shell pwd)/$(APP_NAME)
ICON_PATH = icon.png
DESKTOP_FILE = $(APP_NAME).desktop

install: $(DESKTOP_INSTALL_PATH) $(ICON_INSTALL_PATH)
	# Copier l'icône
	cp $(ICON_PATH) $(ICON_INSTALL_PATH)/$(APP_NAME).png

	# Créer le fichier .desktop
	echo "[Desktop Entry]" > $(DESKTOP_FILE)
	echo "Version=1.0" >> $(DESKTOP_FILE)
	echo "Name=$(APP_NAME)" >> $(DESKTOP_FILE)
	echo "Comment=Un jeu de clicker basé sur les mèmes d'Internet" >> $(DESKTOP_FILE)
	echo "Exec=$(EXEC_PATH)" >> $(DESKTOP_FILE)
	echo "Path=$(shell pwd)" >> $(DESKTOP_FILE)
	echo "Icon=$(ICON_INSTALL_PATH)/$(APP_NAME).png" >> $(DESKTOP_FILE)
	echo "Terminal=false" >> $(DESKTOP_FILE)
	echo "Type=Application" >> $(DESKTOP_FILE)
	echo "Categories=Game;" >> $(DESKTOP_FILE)

	# Installer le fichier .desktop
	cp $(DESKTOP_FILE) $(DESKTOP_INSTALL_PATH)/
	chmod +x $(DESKTOP_INSTALL_PATH)/$(DESKTOP_FILE)

	# Mettre à jour la base de données des icônes
	xdg-icon-resource forceupdate
