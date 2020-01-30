inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("southwest","/wizards/luminarc/mountain/bot1");
  add_exit("north","/wizards/luminarc/mountain/bot3");
  add_exit("cave","/wizards/luminarc/mountain/cave11");
  short_desc="Lower part of the mountain";
  long_desc="The lower part of the mountain is getting little bit cooler\n"+
            "only some bushes and small trees are growing here. other plants\n"+
            "has wasted away becourse the cold air. only some confused bees\n"+
            "are trying to live in here. but the they are not going to live\n"+
            "long in here\n";  
  property = allocate(1);
  set_light(3);
}

