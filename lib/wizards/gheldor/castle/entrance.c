inherit "/room/room";

#define CASTLE "BMC"
#define SAVE_FILE "/castle/save/"+CASTLE+"access_1"
string *access;
int i;

reset(arg) {
  if (arg) return;
  access = ({ });
  short_desc = "Inside of the HUGE Black Marmor Castle at the entrance";
  long_desc =
"The walls are very interesting as it's marmour shines with bright dark\n"+
"light, it surely has some spells on it as it sizzles with magic. The\n"+
"letters are some old runes that only some very high archmage could \n"+
"recognize and even then, it may remain as mystery how it has been done\n"+
"and how it shall go on. The only thing you notice, is that the place seems\n"+
"as an old building as it's artitech view and in general view it looks like\n"+
"it would have appeared in a puff of smoke just few minutes ago.\n";
  add_exit("out", "/wizards/gheldor/workroom.c");
  property = ({ "no_summon", });
  set_light(3);
  restore_object(SAVE_FILE);
  // if!access) save_object(SAVE_FILE);
}

status check_access() {
  if(!member_array(this_player()->query_real_name(),access) != -1
     && this_player()->query_wiz() < 3
     && this_player()->query_real_name() != "gheldor") return 0;
  return 1;
}
init() {
  ::init();
  if(!check_access()) {
    tell_object(this_player(),"Sorry, but you don't have access to this castle.\n");
    command("out",this_player());
  }
  if(check_access()) {
    add_action("list_access","list");
    add_action("add_access","add");
    add_action("remove_access","remove");
    add_action("request","request");
  }
}

status list_access() {
  if(!check_access()) return 0;
 // int i;
  write("Following people have access to this castle:\n");
  if(!access) { write("None.\n"); return 1; }
  for(i=0;i<sizeof(access);i++) write(capitalize(access[i])+".\n");
  write("Total "+sizeof(access)+" people has access to this castle.\n");
  return 1;
}

request(string str) {
  if(!check_access()) return 0;
  if(!str) { write("Request what?\n"); return 1; }
  log_file("castle/"+CASTLE+"_request","[*"+ctime()+"*] - "+str+"\n");
  write("You requested for "+str+"\n");
  return 1;
}

add_access(string str) {
  if(!check_access()) return 0;
  str = lower_case(str);
  if(!find_player(str)) { write("Can't find that player.\n"); return 1; }
  if(member_array(str,access) != -1) { write("That player is already on the list.\n"); return 1; }
  access += ({ str, });
  write("Added "+capitalize(str)+" on the access list.\n");
  return 1;
}

remove_access(string str) {
  if(!check_access()) return 0;
  str = lower_case(str);
  if(!member_array(str,access) != -1) { write("That player isn't on the list.\n"); return 1; }
  access -= ({ str, });
  write("Removed "+capitalize(str)+" from the access list.\n");
  return 1;
}


