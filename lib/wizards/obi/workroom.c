inherit "room/room";

reset(status arg) 
{
	if(arg) return;
  	/* give the exits (M) */
  	add_exit("inn","/world/city/inn");
  	add_exit("cs","/world/city/cs");
    	add_exit("post","/world/city/post");

  	/* give the description for the room (M) */
  	short_desc = "Obi's dark lair!";
  	long_desc = "You have arrived at the deepest level of Hell. Here the mightiest demons and devils roam.\n"+
		"This room feels alive and answers to it's master Obi.\n";

  	/* This defines light level. If you use 'set_not_out(1);' the room will
	have light level 0, unless you 'set_light([arg])'. If 'set_not_out(1);' is
	not used, the room will automatically get it's light depending on the time
	of the day: 1 in night, 2 in the evening and morning and 3 in days. */

	  set_not_out(1);		/* Optional, explained previously */
	  set_light(0);		        /* Optional, explained previously */
	
	
	  /* make some special look targets (m) */
	  items = allocate(2);
	  items[0] = "demon";
	  items[1] = "Where?!";
	
	  /* some special features (?) */
	  property = allocate(1);
	  property[0] = "no_summon";
}

/* the below lines are for more skilled coders :) */

init() {
  ::init(); /* don't forget this, if you use init() */
  add_action("obi", "obi");
}

/* when a player starts his command with "yeah", this func is called. */
/* str is the string (text) that the player possibly writes after "yeah" */
/* ex. "yeah this rocks" -> str == "this rocks" */

obi(str) {
  if(str == "rocks") {
    write("Yes he sure does!\n"); /* the "\n" changes the line :) */
    return 1; /* stop the execution */
  }
  /* "Blaah." will be writed, if the argument (str) is not "this rocks" */
  write("Phuck off!!!!\n");
  return 1;
}







