inherit "room/room";

/* this is a simple room without monsters */
/* (M) = must  (m) = recommanded  (?) = don't use these too much, only for special locations. */

reset(arg) {
  /* give the exits (M) */
  add_exit("north","/wizards/celtron/newroom");
  add_exit("jumpup","/wizards/celtron/newroom");

  /* give the description for the room (M) */
  short_desc = "A room";
  long_desc = "This is an anonymous room.\n"+
		"Ain't it wondelful?\n";

  /* This defines light level. If you use 'set_not_out(1);' the room will
have light level 0, unless you 'set_light([arg])'. If 'set_not_out(1);' is
not used, the room will automatically get it's light depending on the time
of the day: 1 in night, 2 in the evening and morning and 3 in days. */

  set_not_out(1);		/* Optional, explained previously */
  set_light(3);		        /* Optional, explained previously */


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

/* the below lines are for more skilled coders :) */

init() {
  ::init(); /* don't forget this, if you use init() */
  add_action("yeah", "yeah");
}

/* when a player starts his command with "yeah", this func is called. */
/* str is the string (text) that the player possibly writes after "yeah" */
/* ex. "yeah this rocks" -> str == "this rocks" */

yeah(str) {
  if(str == "this rocks") {
    write("It sure does.\n"); /* the "\n" changes the line :) */
    return 1; /* stop the execution */
  }
  /* "Blaah." will be writed, if the argument (str) is not "this rocks" */
  write("Blaah.\n");
  return 1;
}

