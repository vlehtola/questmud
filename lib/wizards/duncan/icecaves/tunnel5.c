inherit "room/room";


int searched=0;

reset(arg) {

  if(arg) return;

  add_exit("north", "/wizards/duncan/icecaves/tunnel6.c");
  add_exit("south", "/wizards/duncan/icecaves/tunnel4.c");

  short_desc = "A narrow tunnel";
  long_desc = "The narrow tunnel is formed by the ancient lava flow. Nowadays it's covered\n"+ 
              "with thick layer of ice and snow. There are icicles hanging from the ceiling.\n"+
              "The ground is slippery and rough. You can see clearly in here because the\n"+
              "tunnel is lit up with strange blue light, which shimmers from the walls under\n"+
              "the thick ice layer. Couple pillars are rising throught the icy ground. Cold\n"+
              "air is floating around the tunnel. The tunnel is serpentine, therefore you\n"+
              "can't see ahead. It's very quiet and peaceful in here, but extremely cold. The\n"+
              "river which is running on the ground, vanishes through the hole in the eastern\n"+
              "wall.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(8);
   items[0] = "icicles";
   items[1] = "The icicles are hanging from the ceiling. They are different sized and shaped. Some of them are swaying dangerously, like they would fall at any moment.";
   items[2] = "pillars";
   items[3] = "The different sized and shaped pillars are rising from the ground. They are almost blocking the way to deeper underground.";
   items[4] = "river";
   items[5] = "The river vanishes through the hole in the eastern wall.";
   items[6] = "hole";
   items[7] = "The hole is too small for any race to enter. Only small animals like rats can get through the hole.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
