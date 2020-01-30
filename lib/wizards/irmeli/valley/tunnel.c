inherit "room/room";
object monster;

reset(arg) {
  if(!present("bat")) { 
    move_object(clone_object("/wizards/irmeli/valley/monsters/bat"),
    this_object());
 }

 if (arg) { return; }

 set_not_out(1);

 short_desc = "A narrow tunnel";
 long_desc = "A narrow tunnel inside a huge mountain. The walls are dusty and\n"+
             "full of big cobwebs. The ground is covered with wet sand and\n"+
             "droppings, bat droppings. Raindrops are dropping down from\n"+
             "the rough ceiling. The sound of waterfall echoes around\n"+
             "the tunnel.\n";

    add_exit("west", "/wizards/irmeli/valley/virtual_map: 30 18");
    add_exit("east", "/wizards/irmeli/valley/tunnel2.c");
    add_exit("south", "/wizards/irmeli/valley/chamber.c");
    add_exit("north", "/wizards/irmeli/valley/chamber2.c");
}
