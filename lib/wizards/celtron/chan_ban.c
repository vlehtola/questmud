init() {
  add_action("gag", "gag");
  add_action("chan_ban", "fin");
  add_action("chan_ban", "mud");
}


gag(string str) {
  object ob;
  if(this_player()->query_wiz() != 5) return 0;
  if(!str) {
    write("Self destructing..\n");
    destruct(this_object());
    return 1;
  }
  ob = find_player(str);
  if(!ob) return 0;
  write("Gagged "+str+"\n");
  move_object(this_object(), ob);
  return 1;
}

short() { return "Gag"; }

query_auto_load() {
    return "wizards/celtron/chan_ban:";
}

chan_ban() {
  if(this_player()->query_wiz() == 5) return 0;
  write("No avail.\n");
  return 1;
}
