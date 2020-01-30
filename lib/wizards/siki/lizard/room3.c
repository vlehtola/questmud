inherit "room/room";
object monster, monster2;

reset(arg) {
    if(!monster) {
       if(arg) return;
       monster = clone_object("/wizards/siki/lizard/monsters/liz_guard");
       move_object(monster, this_object());
       }
    if(!monster2) {
       monster2 = clone_object("/wizards/siki/lizard/monsters/liz_guard2");
       move_object(monster2, this_object());
     }


  add_exit("north","/wizards/siki/lizard/room8");
  add_exit("south","/wizards/siki/lizard/room15");
  add_exit("west","/wizards/siki/lizard/room1");
  add_exit("enter","/wizards/siki/lizard/hut1");

  short_desc = "Outside of a tiny straw hut";
  long_desc = "A tiny hut made out of straws is located east from you.\n"+
              "The ground is tough and damp. Humidity of this place\n"+
              "makes you feel uncomfortable.\n";
}

