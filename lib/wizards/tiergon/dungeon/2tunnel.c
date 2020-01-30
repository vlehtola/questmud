inherit "room/room";

reset(arg) {
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/2xroad");
add_exit("south","/wizards/tiergon/dungeon/a2");
  short_desc = "A roughly-hewn tunnel";
  long_desc = "This tunnel is of rougher make than the one above.\n"+
                "The gray walls are covered with a thick layer of dust that makes you cough.\n";
}
