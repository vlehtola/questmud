inherit "room/room";
object monster;

reset(arg) {
  if(!present("animal 2")) { 
    move_object(clone_object("/wizards/duncan/icecaves/monsters/animal.c"),
    this_object());
    move_object(clone_object("/wizards/duncan/icecaves/monsters/animal.c"),
    this_object());
}

  if(arg) return;

  add_exit("east", "/wizards/duncan/icecaves/tunnel1.c");
  add_exit("out", "/wizards/duncan/icecaves/ledge.c");

  short_desc = "A narrow tunnel inside the mountain";
  long_desc = "The tunnel is formed by the ancient lava flow, therefore it's narrow. There is\n"+ 
              "more than two meters thick ice layer covering the walls, ceiling and ground.\n"+
              "Some icicles are hanging from the ceiling, swaying dangerously. Different sized\n"+
              "and shaped pillars are rising from the ground. The ground is slippery and\n"+
              "rough. The tunnel is lit up with strange blue light, which shimmers from the\n"+
              "walls under the ice layer. You can feel the cold air floating from the depths\n"+
              "of mountain.\n";

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
