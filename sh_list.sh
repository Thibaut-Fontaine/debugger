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
