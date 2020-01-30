inherit "room/room";

reset(arg) {
  add_exit("north","/wizards/celtron/newroom");
  add_exit("jumpup","/wizards/celtron/newroom");

  short_desc = "A room";
  long_desc = "This is an anonymous room.\n"+
		"Ain't it wondelful?\n";

  items = allocate(4);
  items[0] = "jeesmies";
  items[1] = "Jeesmies looks cool";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}


