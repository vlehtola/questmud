inherit "room/room";
object monster;

reset(arg) {
      if(!monster) {
          monster = clone_object("/wizards/siki/lizard/monsters/fe_liz");
          move_object(monster, this_object());
      }
   if(arg) return;


  add_exit("east","/wizards/siki/lizard/room14");
  add_exit("north","/wizards/siki/lizard/room12");


  short_desc = "A sinister swamp";
  long_desc = "The ground is tough and damp. Humidity of this place\n"+
              "makes you feel uncomfortable.\n";
}

