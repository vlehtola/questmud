cmd_stats(string arg) {
  object tp;
  if(arg && this_player()->query_wiz())
    tp = find_player(arg);
  if(!tp) tp = this_player();
  write("Str: " + tp->query_str() + " Dex: " + tp->query_dex() + " Con: " + tp->query_con() +
    " Int: " + tp->query_int() + " Wis: " + tp->query_wis() + " Size: " + tp->query_size() + "\n");
  return 1;
}   

