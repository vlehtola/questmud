inherit "room/room"; 

reset(arg) {
 
  add_exit("down","/wizards/walla/area2/rooms/entrance");
  add_exit("up","/wizards/walla/area2/rooms/stairs/3");
  short_desc = "Near the bottom of a huge staircase";
  long_desc = 
"The stairs that you have started to ascend seem really steep. Only\n" +
"have you taken a few steps, when already the ground seems to shrink\n" +
"very rapidly. You wonder where the stairs lead, and who has had them\n" +           
"built, and why.\n";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
    
}
