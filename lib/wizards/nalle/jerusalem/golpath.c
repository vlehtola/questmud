inherit "room/room";
reset(arg) {
  property = allocate(1);
  property[0] = "no_summon"; 
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/golb2");
  add_exit("west","wizards/nalle/jerusalem/golb2");
  add_exit("east","wizards/nalle/jerusalem/golb2");
  add_exit("south","wizards/nalle/jerusalem/golb2");
  short_desc = "The way to Golgatha";
  long_desc =
"You are on a path leading to the south,\n" +
"meandering upwards between houses and other buildings up\n" +
"to a hill, further away. Dozens of people are gathered here\n" +
"to stone the convicts that are to be crucified.\n";
}


