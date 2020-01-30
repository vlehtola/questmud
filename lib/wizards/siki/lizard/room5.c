inherit "room/room";
object monster, monster2;

reset(arg) {
    if(!monster) {
       monster = clone_object("/wizards/siki/lizard/monsters/child");
       move_object(monster, this_object());
       }
    if(!monster2) {
       monster2 = clone_object("/wizards/siki/lizard/monsters/child");
       move_object(monster2, this_object());
     }
   if(arg) return;

  add_exit("north","/wizards/siki/lizard/room6");
  add_exit("east","/wizards/siki/lizard/room1");
  add_exit("south","/wizards/siki/lizard/room14");
  add_exit("west","/wizards/siki/lizard/room12");

  short_desc = "A sinister swamp";
  long_desc = "The ground is tough and damp. You can feel the humidity\n"+
              "of the air as it fills your lungs. An uncomfortable feeling\n"+
              "fills you.\n";
}

