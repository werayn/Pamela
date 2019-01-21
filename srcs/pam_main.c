/*
** EPITECH PROJECT, 2017
** PAM juniqu_v
** File description:
** main
*/

#include "pam.h"

static bool	open_box(const char *user)
{
  char	*home;

  if (!(home = get_dir(user)))
    return (false);
  else if (check_key(user) == false)
  {
    create_box(user, home);
    return (mount_box(user, home, true));
  }
  else
  	return (mount_box(user, home, false));
}


static bool	close_box(const char *user)
{
  char	cmd[4096];
  char	*home;

  if (!(home = get_dir(user)))
    return (false);
  sprintf(cmd, "umount %s/secure_data-rw && cryptsetup luksClose secure_data_%s", home, user);
  return (my_exec(cmd));
}


PAM_EXTERN int	pam_sm_open_session(pam_handle_t *pamh, int flags, int ac, const char **av)
{
  (void)flags;
  (void)ac;
  (void)av;
  const char	*user;
  
  if (pam_get_user(pamh, &user, "Username :") != PAM_SUCCESS)
    return (PAM_SESSION_ERR);
  else if (open_box(user) == false)
  {
    printf("User: %s, pamela can't mount your container.\n", user);
    return (PAM_SESSION_ERR);
  }
  else
  	return (PAM_SUCCESS);
}

PAM_EXTERN int	pam_sm_close_session(pam_handle_t *pamh, int flags, int ac, const char **av)
{
  (void)flags;
  (void)ac;
  (void)av;
  const char	*user;
  
  if (pam_get_user(pamh, &user, "Username :") != PAM_SUCCESS)
    return (PAM_SESSION_ERR);
  else if (close_box(user) == false)
  {
    printf("User: %s, pamela can't umount your container.\n", user);
    return (PAM_SESSION_ERR);
  }
  else
  	return (PAM_SUCCESS);
}