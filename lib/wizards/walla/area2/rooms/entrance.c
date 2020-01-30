inherit "room/room"; 

reset(arg) {
 
  add_exit("west","/wizards/walla/workroom");
  add_exit("up","/wizards/walla/area2/rooms/stairs/2");
  short_desc = "At the bottom of a huge staircase";
  long_desc = 
"The strange view that you have had for many miles now stands\n" +
"in front of you. Ahead of you lies a huge staircase. where these\n" +
"stairs lead, you have no idea, since clouds cover the upper part\n" +           
"of them. The stairs seem to have been crafted many years ago, and\n" +
"on both sides of the stairs are two huge pilars.\n";

  items = allocate(4);                
  items[0] = "stairs";
  items[1] = "Very old stairs, leading up to the skies";
  items[2] = "pilar"; 
  items[3] = "Two huge pilars on both sides of the stairs";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
    
}

