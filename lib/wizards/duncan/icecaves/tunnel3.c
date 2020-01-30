inherit "room/room";
object monster;

int searched=0;

reset(arg) {
  if(!present("ogre")) { 
    move_object(clone_object("/wizards/duncan/icecaves/monsters/ogre.c"),
    this_object());
   
}

  if(arg) return;

  add_exit("east", "/wizards/duncan/icecaves/tunnel4.c");
  add_exit("west", "/wizards/duncan/icecaves/tunnel2.c");
  add_exit("north", "/wizards/duncan/icecaves/hall4.c");
  add_exit("south", "/wizards/duncan/icecaves/hall5.c");

  short_desc = "A widening tunnel";
  long_desc = "Formed by the ancient lava flow, the tunnel is widening all the time. Nowadays\n"+ 
              "it's covered with thick layer of ice and snow. There are icicles hanging from\n"+
              "the ceiling. The ground is slippery and rough. A frozen-in small river is\n"+
              "running on the ground, ending somewhere in the bowels of the earth. You can\n"+
              "see clearly in here because the tunnel is lit up with strange blue light,\n"+
              "which shimmers from the walls under the thick ice layer. Couple pillars are\n"+
              "rising through the icy ground. Two small halls are in north and south, formed\n"+
              "by the ancient lava flow. Cold air is floating around the tunnel. The tunnel\n"+
              "leads deeper inside the mountain towards east.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(6);
   items[0] = "icicles";
   items[1] = "The icicles are hanging from the ceiling. They are different sized and shaped. Some of them are swaying dangerously, like they would fall at any moment";
   items[2] = "pillars";
   items[3] = "The different sized and shaped pillars are rising from the ground. They are almost blocking the way to deeper underground";
   items[4] = "river";
   items[5] = "A small frozen-in river is running on the ground. It ends somewhere in the bowels of the earth";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
