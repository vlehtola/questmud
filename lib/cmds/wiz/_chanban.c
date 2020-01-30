//written by C

#define CHANBAN_D "/daemons/chanban_d"

cmd_chanban(string arg) {
  int time;
  string name;
  string chan;
  if(!arg || sscanf(arg, "%s %s %d", name, chan, time) != 3) {
    write("Usage: chanban <name> [<chan>|all] <time>\n");
    write("NOTE! Time is hours.\n");
    return 1;
  }
  CHANBAN_D->add_ban(name,chan, time);
  write("Banned.\n");
  return 1;
}
