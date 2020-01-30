inherit "room/room";

init() {
  ::init();
  add_action("open", "open");
}

open(str) {
  if(str != "gates") return;
  write("The graveyard gates open with a swing.\n");
  say(this_player()->query_name()+" opens the gates to the graveyard.\n");
  add_exit("north","/wizards/walla/areas/mg/rooms/44");
  return 1;
}

object monster;
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/areas/mg/mobs/cur");
    move_object(monster, this_object());
  }
  call_other("/wizards/moonstar/areas/asgroth/virtual_map", "XX", 0);
  if(arg) return;
  add_exit("south","/wizards/moonstar/areas/asgroth/virtual_map: 18 8");
  short_desc = "At the gates to the graveyard";
  long_desc =
  long_desc =
"The noises and the worries of the city seem to leave you as you stand here\n" +
"looking in at the graveyard. The graveyard radiates a calming breeze that \n" +
"that makes you feel quite at home. You can see lines of graves up ahead,\n" +
"and some bigger tombs that stand tall as small houses. There are gates that\n"+
"lead to the cemetary.\n";
}
