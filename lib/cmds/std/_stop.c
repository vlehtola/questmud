cmd_stop() {
  if (this_player()->query_attack()) {
   write("You can't do that while being attacked.\n");
   return 1;
  }
  write("Attempting to stop hunting...\n");
  this_player()->reset_hunter_list();
  return 1;
}
