/*
** EPITECH PROJECT, 2017
** PAM juniqu_v
** File description:
** box
*/

#include "pam.h"

void	create_box(const char *user, char *home)
{
  char	cmd[4096];
  char	path[1024];

  if (create_key(home) == false)
    return ;
  sprintf(path, "%s/.secure_data-rw", home);
  sprintf(cmd, "dd if=/dev/zero of=%s bs=1 count=0 seek=1G && chown %s:%s %s && chmod 400 %s && cryptsetup luksFormat %s %s/.key", path, user, user, path, path, path, home);
  my_exec(cmd);
  return ;
}

bool		mount_box(const char *user, char *home, bool first)
{
  char	cmd[4096];
  char	path[1024];

  sprintf(path, "%s/secure_data-rw", home);
  if (access(path, F_OK) == -1)
  {
    sprintf(cmd, "mkdir %s", path);
    if (my_exec(cmd) == false)
      return (false);
  }
  sprintf(cmd, "cryptsetup luksOpen %s/.secure_data-rw secure_data_%s --key-file %s/.key", home, user, home);
  if (first)
    sprintf(cmd, "%s && mkfs.ext4 /dev/mapper/secure_data_%s", cmd, user);
  sprintf(cmd, "%s && mount /dev/mapper/secure_data_%s %s && chown -R %s:%s %s && chmod 700 %s", cmd, user, path, user, user, path, path);
  return (my_exec(cmd));
}
