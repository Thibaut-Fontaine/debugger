# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    replace.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 19:46:56 by tfontain          #+#    #+#              #
#    Updated: 2017/01/23 19:58:18 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
OLD="#include \"libft.h\""
NEW="#include \"includes\/libft.h\""
DPATH="*.c"
BPATH="~/tfontain/backup"
TFILE="/tmp/out.tmp.$$"
[ ! -d $BPATH ] && mkdir -p $BPATH || :
for f in $DPATH
do
  if [ -f $f -a -r $f ]; then
    /bin/cp -f $f $BPATH
   sed "s/$OLD/$NEW/g" "$f" > $TFILE && mv $TFILE "$f"
  else
   echo "Error: Cannot read $f"
  fi
done
/bin/rm $TFILE
