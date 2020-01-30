inherit "room/room";

object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/moraloth/guard");
    move_object(monster, this_object());
  }

  if(arg) return;

  add_exit("west","out: 260 82");
  add_exit("northwest","out: 260 82");
  add_exit("southwest","out: 260 82");
  add_exit("northeast","out: 260 82");
  add_exit("southeast","out: 260 82");
  add_exit("south","out: 260 82");
  add_exit("north","out: 260 82");
  add_exit("enter","/wizards/proge/moraloth/forest1");

  short_desc =
"Entrance to the cursed forest";

  long_desc = 

"In the edge of the forest. There is a forest in the east,\n"+
"known to be damned by some evil spirits. You see no trails\n"+
"leading in to the forest.\n";


}


