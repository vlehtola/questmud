status cmd_reply(string arg)
{
  if(!arg)
  {
    write("Reply what ?\n");
    return 1;
  }
  if(!this_player()->query_last_teller())
  {
    write("No one hasn't told you anything yet.\n");
    return 1;
  }
  "/cmds/std/_tell"->cmd_tell(this_player()->query_last_teller()+" "+arg);
  return 1;
}
