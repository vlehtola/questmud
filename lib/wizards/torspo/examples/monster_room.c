inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { /* if the monster is dead */
    monster = clone_object("/wizards/celtron/area5/monsters/spider");
    move_object(monster, this_object());
  }
  /* if you put the clone and move below the return line, monster will only reset after reboot. */
  if(arg) return;

  add_exit("north","/wizards/celtron/newroom");
  /* give the description for the room (M) */
  short_desc = "A room";
  long_desc = "This is an anonymous room.\n"+
		"Ain't it wondelful?\n";

}


