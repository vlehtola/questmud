/* retell command for Questmud by Cendor at 080599 */

status cmd_retell(string arg)
{
  if(!arg)
  {
    write("Retell who ?\n");
    return 1;
  }
  if(!this_player()->query_last_msg())
  {
    write("You haven't told anyone anything yet.\n");
    return 1;
  }
  "/cmds/std/_tell"->cmd_tell(arg+" "+this_player()->query_last_msg());
  return 1;
}
