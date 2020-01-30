inherit "room/room";
 
special locations. */
 
reset(arg) {
  /* give the exits (M) */
  add_exit("north","/wizards/morgoth/cannibal/room/path1");
  add_exit("south","/wizards/morgoth/workroom");
 
  /* give the description for the room (M) */
  short_desc = "A room";
  long_desc = "This is an anonymous room.\n"+
                "Ain't it wondelful?\n";
 
  /* make some special look targets (m) */
  items = allocate(4);
  items[0] = "jeesmies";
  items[1] = "Jeesmies looks cool";
 
  /* some special features (?) */
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}
 
 
init() {
  ::init(); /* don't forget this, if you use init() */
  add_action("yeah", "yeah");
}
 
 
yeah(str) {
  if(str == "this rocks") {
    write("It sure does.\n"); /* the "\n" changes the line :) */
    return 1; /* stop the execution */
  }
  /* "Blaah." will be writed, if the argument (str) is not "this rocks" */
  write("Blaah.\n");
  return 1;
}
