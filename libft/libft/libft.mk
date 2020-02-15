# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquincy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 22:13:23 by jquincy           #+#    #+#              #
#    Updated: 2019/11/20 23:53:35 by jquincy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_FT	?= .

FT_NAME	:= libft.a

FT_LNK	:= -L $(L_FT) -l ft
FT_INC	:= -I $(L_FT)/includes
FT_LIB	:= $(L_FT)/$(FT_NAME)

ifndef LIB_LNK
LIB_LNK	:=
LIB_INC	:=
endif

LIB_LNK	+= $(FT_LNK)
LIB_INC	+= $(FT_INC)
