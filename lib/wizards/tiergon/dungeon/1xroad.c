inherit "room/room";

reset(arg) {
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/top1");
add_exit("south","/wizards/tiergon/dungeon/toptunnel");
add_exit("down","/wizards/tiergon/dungeon/2xroad");
  short_desc = "On top of the mineshaft";
  long_desc = "A twisting staircase carved on the edges of the mineshaft continues downwards.\n"+
                "This tunnel continues further northwards\n";
}
