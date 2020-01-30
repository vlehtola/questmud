inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/seweel");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/sewf1");
  add_exit("south","wizards/nalle/jerusalem/sewg2");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"You are in a smelly passage of the sewers of Jerusalem.\n"+
"Sewage water flows at quite a pace here and eels attach\n"+
"themselves to every possible non-clad parts of your body.\n"+
"It is quite dark in this passage and you are only guided\n"+
"by the light that shines in through the grates on the ground\n"+
"level. This passage continues to the east and to the west.\n";

  set_water(4);
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/sewmap");
   return 1;
}

