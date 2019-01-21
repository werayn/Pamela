/*
** EPITECH PROJECT, 2017
** PAM juniqu_v
** File description:
** incs
*/

#ifndef _PAM_H_
 #define _PAM_H_

#define PAM_SM_SESSION

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pwd.h>
#include <libcryptsetup.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

char	*get_dir(const char *);
bool	my_exec(char *);
bool	create_key(const char*);
bool	check_key(const char*);
void	create_box(const char *, char *);
bool	mount_box(const char *, char *, bool);

#endif /* !pamh.h */
