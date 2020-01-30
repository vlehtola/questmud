inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "Jail";
    long_desc = "You have been a really bad person, you shall wait here for your punishment!\n";
    property = allocate(4);
    property[0] = "no_kill";
    property[1] = "no_skill";
    property[2] = "no_spell";
    property[3] = "no_summon";
}

init() {
   ::init();
   add_action("denied","",1);
}

denied(string str) {
  string *options;
  if(str) options = explode(str," ");
  if(str == "l" ||str == "look") return 0;
  if(options) if(options[0] == "l"|| options[0] == "look") return 0;
  if(this_player()->query_wiz()) return 0;
  write("You are tied to the wall and gagged, you can't do anything.\n");
  return 1;
}
