inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd6");
  add_exit("east","wizards/nalle/jerusalem/vd8");
  short_desc = "Via Dolorosa (7th block)";
  long_desc =
"This is the sixth block of the Via Dolorosa, the entry to\n" +
"to David's Tower and the path to Golgatha are to your east. David's\n" +
"tower, the massive building made of chalkstone that looms to your\n" +
"northeast, is rumoured to actually be a prison, where a beautiful\n" +
"maiden is confied, waiting to be wed to the king. But those rumours\n"+
"are probably no more then the product of the minds of idle women.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd7map");
   return 1;
}
