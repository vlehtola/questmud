inherit "room/room"; 
 
reset(arg) {
 
  add_exit("north","/wizards/walla/dl/map; 54 6");
  add_exit("south","/wizards/walla/workroom");
  short_desc = "A small mountanous path leading to the outworld";
  long_desc =
"no fucking long desc here.\n";
 
  items = allocate(4);
  items[0] = "moon";
  items[1] = "You see the two moons up in the sky, living in harmony";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
 
}


