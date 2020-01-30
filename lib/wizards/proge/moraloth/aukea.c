inherit "room/room";

object monster;

reset(arg) {

  if(arg) return; /* this one before the monster creation */

  if(!monster) { 
    monster = clone_object("/wizards/proge/moraloth/guardian");
  }

  add_exit("northwest","/wizards/proge/moraloth/path");

  short_desc =
"Opening in the middle of Moraloth";

  long_desc = 
"You've come to the middle of the damned forest. There is dried\n"+
"blood lying on the grass and weird kind of stones piled in the\n"+
"center of the opening. It could be an altar to somekind of evil\n"+
"ritual. Trees in the edge of the opening seem to have died long\n"+
"ago and they are standing leafless and still.\n";

}

init() {
  ::init();
  add_action("look", "look");
}

look(str) {
   if(str == "at stones") {
   write("You see a large pile of stones. They're all covered with\n"+
         "dried blood. This must be a sacrificial altar of somekind.\n");
   if (monster) {
     call_out("mosa_melkein", 4);
   }
   return 1;
   }
   return;
}

mosa_melkein() {
   write("You sense evil.\n");
   say("You sense evil.\n");
   call_out("mosa_esiin", 3);
   return 1;
}

mosa_esiin() {
   write("Suddenly a huge undead rises behind the pile of stones.\n"+
         "Guardian shouts: Mortal fools, prepare to die!\n");
   say("Suddenly a huge undead rises behind the pile of stones.\n"+
         "Guardian shouts: Prepare to die!\n");
   move_object(monster, this_object());
   return 1;
}

