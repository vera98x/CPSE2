#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := ball.cpp rectangle.cpp 

# header files in this project
HEADERS := ball.hpp rectangle.hpp object.hpp 

# other places to look for files for this project
SEARCH  := ../w1-library

run: ./main


# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
