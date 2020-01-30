inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
      monster = clone_object("/wizards/siki/lizard/monsters/liz");
      move_object(monster, this_object());
      }
   if(arg) return;

  add_exit("north","/wizards/siki/lizard/room3");
  add_exit("west","/wizards/siki/lizard/room4");


  short_desc = "Shore";
  long_desc = "South of you lies a small lake. The water is calm, there\n"+
             "are no waves anywhere. The ground is soft here and it slopes\n"+
            "to the lake.\n";

}


