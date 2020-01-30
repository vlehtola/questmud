inherit "room/room";
object monster;

reset(arg) {
  if(!present("phantom")) { 
    move_object(clone_object("/wizards/irmeli/valley/monsters/phantom"),
    this_object());
  }  

 if (arg) { return; }

 set_not_out(1);

 short_desc = "A narrow tunnel";
 long_desc = "A narrow tunnel inside a huge mountain. The walls are dusty and\n"+
             "full of big cobwebs. The ground is covered with wet sand.\n"+
             "Raindrops are dropping down from the rough ceiling. The sound\n"+
             "of waterfall echoes around the tunnel.\n";

    add_exit("east", "/wizards/irmeli/valley/virtual_map: 31 18");
    add_exit("west", "/wizards/irmeli/valley/tunnel.c");
    add_exit("south", "/wizards/irmeli/valley/chamber3.c");
    add_exit("north", "/wizards/irmeli/valley/chamber4.c");
}
