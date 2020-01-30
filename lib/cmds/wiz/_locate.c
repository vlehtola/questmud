// locates a player or monster. written by C

cmd_locate(string arg) {
  object ob;
  if(!arg) {
     write("Syntax: locate <name>\n");
     return 1;
  }
  ob = find_player(arg);
  if(!ob) ob = find_living(arg);
  if(!ob) ob = find_object(arg);

  if(!ob) {
    write("Not found.\n");
    return 1;
  }
  if(!environment(ob)) {
    write("Found outside environment. ("+file_name(ob)+")\n");
    return 1;
  }
  write("Located at "+environment(ob)->short()+" ("+file_name(environment(ob))+")\n");  
  return 1;
}
