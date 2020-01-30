// added chanban, C

#define CHANBAN "/daemons/chanban_d"

status cmd_shout(string str) {
  if(!str) { write("Shout what ?\n"); return 1; }
  if(str == "last") { tail("/log/SHOUT"); return 1; }
  if(this_player()->query_level() < 10) {
    write("You are too weak for this.\n");
    return 1;
  }
  if(CHANBAN->query_ban(this_player()->query_name(),"all")) {
    write("You can't.\n");
    return 1;
  }

  if(this_player()->query_sp() >= this_player()->query_max_sp())
    write_file("/log/SHOUT","["+ctime()[11..15]+"] - "+this_player()->query_name()+" shouts: "+str+"\n");

  return 0;
}

