inherit "room/room";
object monster;

reset(arg) {
      if(!monster) {
          monster = clone_object("/wizards/siki/lizard/monsters/old");
          move_object(monster, this_object());
      }
   if(arg) return;

  add_exit("west","/wizards/siki/lizard/room13");
  add_exit("east","/wizards/siki/lizard/room4");
  add_exit("south","/wizards/siki/lizard/dock1");
  add_exit("north","/wizards/siki/lizard/room5");


  short_desc = "A sinister swamp";
  long_desc = "The ground is tough and damp. Humidity of this place\n"+
              "makes you feel uncomfortable. A small dock lies south from\n"+
              "here.\n";
}

