inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/cs");
  add_exit("south","wizards/nalle/jerusalem/elattar4");
  short_desc = "El Attar (3rd block)";
  long_desc =
"This is the 3rd block od the El Attar road, just south from\n" +
"the central square, and there seems to be loads of people up\n" + 
"in that direction. You are surprised to notice the smell of \n" +
"excrements and vomit, even though this is closer to the\n" +
"poorer neighbourhood. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/elattar3map");
   return 1;
}

