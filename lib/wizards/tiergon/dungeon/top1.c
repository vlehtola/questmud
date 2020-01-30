inherit "room/room";

reset(arg) {
set_not_out(1);
add_exit("south","/wizards/tiergon/dungeon/1xroad");
add_exit("northwest","/wizards/tiergon/dungeon/top2");
  short_desc = "Tunnel";
  long_desc = "The tunnel floor is covered with a beautiful carpet\n"+
                "This was probably the part of the mine shown to prospective buyers, before the problems started\n",0;
items = allocate (2);
items[0] = "carpet";
items[1] = "A beautiful red carpet made from the finest possible materials";
}
