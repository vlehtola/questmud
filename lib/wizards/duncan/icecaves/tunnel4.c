inherit "room/room";


int searched=0;

reset(arg) {

  if(arg) return;

  add_exit("west", "/wizards/duncan/icecaves/tunnel3.c");
  add_exit("north", "/wizards/duncan/icecaves/tunnel5.c");

  short_desc = "A widening tunnel";
  long_desc = "Formed by the ancient lava flow, the tunnel is widening all the time. Nowadays\n"+ 
              "it's covered with thick layer of ice and snow. There are icicles hanging from\n"+
              "the ceiling. The ground is slippery and rough. A frozen-in small river is\n"+
              "running on the ground, ending somewhere in the bowels of the earth. You can\n"+
              "see clearly in here because the tunnel is lit up with strange blue light,\n"+
              "which shimmers from the walls under the thick ice layer. Couple pillars are\n"+
              "rising through the icy ground. Cold air is floating around the tunnel. The\n"+
              "tunnel is making a turn to the right, therefore you can't see ahead. It's very\n"+
              "quiet and peaceful in here, but extremely cold.\n";

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
