# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sh_list.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 02:57:54 by tfontain          #+#    #+#              #
#    Updated: 2017/01/24 02:59:03 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# liste de bash interessants


# a la racine d'un projet git, permet de connaitre l'adresse du repo
git config --get remote.origin.url

# reset un repo a partir du repo deja pushé
# (equivalent d'un git clone mais en gardant le meme dossier)
git reset --hard HEAD

# affiche les fichiers contenant des erreurs de norme, et leurs erreurs
norminette | grep -i -B 1 "Error"

#checker un repo git
clear && echo -n 'folder ' && pwd && echo -n 'at git adress ' && git config --get remote.origin.url && echo -n 'these files are in : ' && ls && git status

#kill Itunes :
ps axww | grep -v grep | grep -i itunes | awk '{print $1}' | xargs kill -9
