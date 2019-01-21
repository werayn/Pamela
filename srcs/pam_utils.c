/*
** EPITECH PROJECT, 2017
** PAM juniqu_v
** File description:
** utils
*/

#include "pam.h"

char	*get_dir(const char *user)
{
  struct passwd	*path;

  if (!(path = getpwnam(user)) || path->pw_dir == NULL)
    return (NULL);
  return (path->pw_dir);
}

bool	my_exec(char *command)
{
  if (system(command) < 0)
    return (false);
  return (true);
}

bool	create_key(const char *home)
{
  char	cmd[4096];
  char	path[1024];

  sprintf(path, "%s/.key", home);
  sprintf(cmd, "dd if=/dev/urandom of=%s bs=1024 count=1 && chown root:root %s && chmod 400 %s", path, path, path);
  return (my_exec(cmd));
}

bool   check_key(const char *user)
{
  char	buff[1024];
  char	*home;

  if (!(home = get_dir(user)))
    return (false);
  sprintf(buff, "%s/.key", home);
  if (access(buff, F_OK) == -1)
    return (false);
  return (true);
}
