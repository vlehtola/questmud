/* punishment method for archs. forcereincs the mortal with 10% exploss
 *   //Celtron
 */

cmd_forcereinc(string arg) {
  object player;
  int percent;
  string plr;
  if(!arg) {
    write("Usage: forcereinc <player> [<exp_loss_percent>]\n");
    return 1;
  }
  if(sscanf(arg, "%s %d", plr, percent) != 2) {
    player = find_player(arg);
  } else {
    player = find_player(plr);
  }
  if(!player) {
    write("No such player online.\n");
    return 1;
  }
  if(percent && this_player()->query_wiz() != 5) {
    write("You don't have rights to choose a percent. Use with player argument only. (Nothing done)\n");
    return 1;
  }
  if(!percent) percent = 10;
  log_file("FORCEREINC", ctime(time())+" "+arg+" by "+this_player()->query_name()+" ("+this_player()->query_wiz()+").\n");
  player->reinc(percent);
  move_object(player,"/obj/race_selection");
  player->save_me(1);
  write("Player "+player->query_name()+" forcereinced.\n");
  shout(
"Divine forces grab "+player->query_name()+" from the ground. An angry bolt of red light strikes "+player->query_objective()+" in midair.\n"+
"Ashes fall down from the sky, scattered by the wind. Justice has been served.\n");
  return 1;
}
