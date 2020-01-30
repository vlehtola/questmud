inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { /* if the monster is dead */
    monster = clone_object("/wizards/nalle/area2/monsters/clown");
    move_object(monster, this_object());
  }
  /* if you put the clone and move below the return line, monster will only
     reset after reboot. */
  if(arg) return;

  add_exit("south","/wizards/nalle/area2/b5");
  /* give the description for the room (M) */
  short_desc = "An old toystore";
  long_desc = "You have arrived into an old toystore\n"+
              "with cobwebs on the walls and dust on\n"+
              "the furniture. You expected the store\n"+
              "to be deserted and are slightly startled\n"+
              "to see a seller, dressed up as a clown.\n";

}
