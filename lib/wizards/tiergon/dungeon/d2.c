inherit "room/room";

reset(arg) {
set_not_out(1);
add_exit("east","/wizards/tiergon/dungeon/d3");
add_exit("northwest","/wizards/tiergon/dungeon/d1");
  short_desc = "An abandoned mining tunnel";
  long_desc = "The gray walls are covered with a thick layer of dust that makes you cough.\n"+
              "The tunnel feels surprisingly cool.\n";
}

