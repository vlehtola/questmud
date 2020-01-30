inherit "room/room";
object monster;



reset(arg) {
  if(!present("warrior 2 ")) { 
    move_object(clone_object("/wizards/duncan/icecaves/monsters/ogre.c"),
    this_object());
    move_object(clone_object("/wizards/duncan/icecaves/monsters/ogre.c"),
    this_object());
}

  if(arg) return;

  add_exit("south", "/wizards/duncan/icecaves/tunnel3.c");

  short_desc = "A small ice-hall";
  long_desc = "A small hall has been formed in here by the ancient lava flow. It's separated\n"+ 
              "from the main tunnel. The walls, ground and ceiling are covered with thick ice\n"+
              "layer and snow. The hall is four meters wide and couple meters long and high,\n"+
              "lit up with shimmering blue light. The light is shimmering through the ice\n"+
              "layer on the walls. There are some icicles hanging from the ceiling. The\n"+
              "ground is rough and slippery, full of different sized and shaped pillars.\n"+
              "Cold air is floating around the hall. The main tunnel is in the south.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(4);
   items[0] = "icicles";
   items[1] = "The icicles are hanging from the ceiling. They are different sized and shaped. Some of them are swaying dangerously, like they would fall at any moment";
   items[2] = "pillars";
   items[3] = "The different sized and shaped pillars are rising from the ground. They are almost blocking the way to deeper underground";
  
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}


