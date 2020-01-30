inherit "room/room";
object monster;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/lizard/monsters/gliz");
      move_object(monster, this_object());
      }
   if(arg) return;


  add_exit("south","/wizards/siki/lizard/room12");
  add_exit("east","/wizards/siki/lizard/room6");

  short_desc = "A sinister swamp";
  long_desc = "The ground is tough and damp. Old dead thick trees\n"+
              "make the swamp look frightening.\n";
             
}



