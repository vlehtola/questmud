inherit "room/room";
object monster;

reset(arg) {
    if(!monster) {
        monster = clone_object("/wizards/siki/lizard/monsters/old");
        move_object(monster, this_object());
        }
    if(arg) return;

  add_exit("east","/wizards/siki/lizard/room7");
  add_exit("south","/wizards/siki/lizard/room6");

  short_desc = "A sinister swamp";
  long_desc = "The ground is tough and damp. You can feel the humidity\n"+
              "of the air as it fills your lungs. An uncomfortable feeling\n"+
              "fills you.\n";
}

