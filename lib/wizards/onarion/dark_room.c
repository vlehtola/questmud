inherit "room/room";

reset(arg) {
  add_exit("west","/wizards/onarion/dark_room2");
  add_exit("jumpup","/wizards/celtron/newroom");

  short_desc = "A room";
  long_desc = "This is an anonymous room.\n"+
		"Ain't it wondelful?\n";

set_not_out(1);
set_light(1);

  items = allocate(4);
  items[0] = "jeesmies";
  items[1] = "Jeesmies looks cool";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}


