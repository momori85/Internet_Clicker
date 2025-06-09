#!/bin/bash
# Forcer l'utilisation de SDL locale dans ~/.local/lib
export LD_LIBRARY_PATH="$HOME/.local/lib:$LD_LIBRARY_PATH"

# Lancer le jeu depuis son dossier
cd "$(dirname "$0")"
exec ./Internet-Clicker

