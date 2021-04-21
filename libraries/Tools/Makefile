##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for c++20
##

BINNAME			:=	$(BINDIR)/lib$(NAME).a

C_SRCEXT		:=	.c
CPP_SRCEXT		:=	.cpp
CPPM_SRCEXT		:=	.cppm

OBJEXT			:=	.o
DEPEXT			:=	.d
PCMEXT			:=	.pcm

## ============================================================================

BINDIR			?=	.
OBJDIR			?=	../../.build/objects
DEPDIR			?=	../../.build/dependencies

CC				:=	gcc
CXX				:=	g++

# find
C_SRC			!=	find . -type f -name \*$(C_SRCEXT)
CPP_SRC			!=	find . -type f -name \*$(CPP_SRCEXT)
CPPM_SRC		!=	find . -type f -name \*$(CPPM_SRCEXT)

# .x=.o
C_OBJ			:=	$(patsubst %$(C_SRCEXT),$(OBJDIR)/%$(OBJEXT),$(C_SRC))
CPP_OBJ			:=	$(patsubst %$(CPP_SRCEXT),$(OBJDIR)/%$(OBJEXT),$(CPP_SRC))
CPPM_OBJ		+=	$(patsubst %$(CPPM_SRCEXT),$(OBJDIR)/%$(OBJEXT),$(CPPM_SRC))

## BINDIR
BINDIR			:=	$(patsubst /%,,$(BINDIR))
BINDIR			:=	$(patsubst ~%,,$(BINDIR))
ifeq "$(BINDIR)" ""
$(error invalid bindir)
endif

## ============================================================================

PRINTF				:=	@printf

NORMAL				:=	\e[0m
BLACK				:=	\e[0;30m
DARKGRAY			:=	\e[1;30m
RED					:=	\e[0;31m
LRED				:=	\e[1;31m
GREEN				:=	\e[0;32m
LGREEN				:=	\e[1;32m
BROWN				:=	\e[0;33m
YELLOW				:=	\e[1;33m
BLUE				:=	\e[0;34m
LBLUE				:=	\e[1;34m
PURPLE				:=	\e[0;35m
LPURPLE				:=	\e[1;35m
CYAN				:=	\e[0;36m
LCYAN				:=	\e[1;36m
LIGHT				:=	\e[0;37m
WHITE				:=	\e[1;37m

## ============================================================================

all : $(BINNAME)

$(BINNAME): $(C_OBJ) $(CPP_OBJ) | $(BINDIR)
	ar -rc $@ $^
	$(PRINTF) "$(LCYAN)[Library:$(NAME)][Linkage]$(NORMAL) lib$(NAME).a\n"

# .c
$(OBJDIR)/%$(OBJEXT): %$(C_SRCEXT)
	mkdir -p $(@D) $(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
	$(CC) -c $(OUTPUT_OPTION) -c $(CPPFLAGS) $(CFLAGS) $< \
		-MT $@ -MMD -MP -MF $(patsubst $(OBJDIR)%$(OBJEXT),$(DEPDIR)/%$(DEPEXT),$(patsubst ./%,%,$@))
	$(PRINTF) "$(LCYAN)[Library:$(NAME)][Compilation]$(NORMAL) $<\n"

# .cpp
$(OBJDIR)/%$(OBJEXT): %$(CPP_SRCEXT) | $(CPPM_OBJ)
	mkdir -p $(@D) $(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
	$(CXX) -c $(OUTPUT_OPTION) $(CPPFLAGS) $(CXXFLAGS) $< \
		-MT $@ -MMD -MP -MF $(patsubst $(OBJDIR)%$(OBJEXT),./$(DEPDIR)/%$(DEPEXT),$(patsubst ./%,%,$@))
	$(PRINTF) "$(LCYAN)[Library:$(NAME)][Compilation]$(NORMAL) $<\n"

# .cppm
$(OBJDIR)/%$(OBJEXT): %$(CPPM_SRCEXT)
	mkdir -p $(@D) $(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
	$(CXX) -o $(patsubst %$(OBJEXT),%$(PCMEXT),$(patsubst ./%,%,$@)) $(CXXMFLAGS) $< \
		-MT $(patsubst %$(OBJEXT),%$(PCMEXT),$(patsubst ./%,%,$@)) -MMD -MP -MF $(patsubst $(OBJDIR)%$(OBJEXT),$(DEPDIR)/%$(DEPEXT),$(patsubst ./%,%,$@))
	$(CXX) $(OUTPUT_OPTION) -c $(CXXFLAGS) $(patsubst %$(OBJEXT),%$(PCMEXT),$(patsubst ./%,%,$@))
	$(PRINTF) "$(LCYAN)[Library:$(NAME)][Compilation][Module]$(NORMAL) $<\n"

$(BINDIR) :; mkdir -p $(BINDIR)

ifneq "$(wildcard $(DEPDIR))" ""
include $(shell find $(DEPDIR) -type f -name \*$(DEPEXT))
endif
