// written by C 7.5.04 for debug purposes

#define STUNOB "/daemons/stunob"

cmd_stun(string arg) {
  object ob;
  int time;
  string name;
  if(sscanf(arg, "%s %d", name, time) == 2) {
    ob = find_player(name);
  } else {
    ob = find_player(arg);
  }
  if(!ob) {
    write("cmd: stun <player_name> [<time_in_rounds>]\n");
    return 1;
  }
  if(!time) time = 10;
  if(!name) name = arg;
  clone_object(STUNOB)->start(ob, time);
  tell_object(ob, "You are STUNNED!\n");
  write("Stunned "+name+" for "+time+" rounds.\n");
  return 1;

}
