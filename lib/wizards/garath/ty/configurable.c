inherit "obj/armour";
string shortti,longi,nimi;

#define LONG_EXTRA "This object is shimmering magically, like it wouldn't enjoy it's form.\n"

void start() {
    if(!shortti) shortti = "A magical object with no real form [G]";
    if(!longi) longi = "A magical object with no real form yet...\n";
    if(!nimi) nimi = "object";
    set_class(0);
    set_slot("held");
    set_name(nimi);
    set_alias("g_object");
    set_short(shortti);
    set_long(longi);
}

void init() {
  ::init();
  add_action("set_help","set_help");
  add_action("set_shortti","set_short");
  add_action("set_longi","set_long");
  add_action("set_nimi","set_name");
}

status set_help() {
  write("Available commands are: set_help, set_short, set_long and set_name\n");
  write("                        Further instructions will be made later...\n");
  return 1;
}

status set_shortti(string str) {
  if(!str) { write("Usage: set_short (short_desc)\n"); return 1; }
  if(strlen(str) > 20) { write("Too long desc...\n"); return 1; }
  if(strlen(str) < 5) { write("Too short desc...\n"); return 1; }
  shortti = str + " [G]";
  write("Short set as: "+shortti+"\n");
  this_object()->reset();
  return 1;
}

status set_longi(string str) {
  string *tmp;
  int i;
  if(!str) { write("Usage: set_long (long_desc)\n"); return 1; }
  if(strlen(str) < 5) { write("Too short desc...\n"); return 1; }
  longi = 0;
  tmp = explode(str,"\\n");
  longi = implode(tmp,"\n");
  longi = longi + "\n" + LONG_EXTRA;
  write("Long desc set as:\n"+longi);
  this_object()->reset();
  return 1;
}

status set_nimi(string str) {
  if(!str) { write("Usage: set_name (name for obj)\n"); return 1; }
  if(strlen(str) > 10) { write("Too long name...\n"); return 1; }
  if(strlen(str) < 2) { write("Too short name...\n"); return 1; }
  nimi = lower_case(str);
  write("Name set as: "+nimi+"\n");
  this_object()->reset();
  return 1;
}
