inherit "room/room";

/* this is a simple room without monsters */
/* (M) = must  (m) = recommanded  (?) = don't use these too much, only for special locations. */

reset(arg) {
  /* give the exits (M) */
add_exit("cs","/world/city/cs");
add_exit("inn","/world/city/inn");

short_desc = "Jeps taa se on Terrorin workroom";
long_desc = "JOoh taa on terrorin workroom souuu jos oot mortti ja kuakkavierai sa nii mees pois.\n";

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

