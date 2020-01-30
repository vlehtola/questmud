inherit "room/room";
object monster;

reset(arg) {
  if(!present("devil")) { 
    move_object(clone_object("/wizards/irmeli/volcano/monsters/devil1.c"),
    this_object());
 }
 if (arg) { return; }
 set_not_out(3);

 short_desc = "A tunnel covered with ash and lava rock";
 long_desc = "A tunnel inside the volcano is covered with ash and lava rock. The tunnel\n"+
             "is lit up with everlasting torches, placed on the walls of the tunnel.\n"+
             "The ground, walls and ceiling of the tunnel are full of different sized\n"+
             "cave paintings from the ancient times. The tunnel falls slightly, bit by\n"+
             "bit, towards the centre of the volcano. The air is getting warmer in the\n"+
             "tunnel. Sulphur and nitrogen gases hovers around the tunnel.\n";

    add_exit("out", "/wizards/irmeli/volcano/entrance.c");
    add_exit("north", "/wizards/irmeli/volcano/tunnel2.c");

  items = allocate(2);
  items[0] = "torch";
  items[1] = ""; 
}
