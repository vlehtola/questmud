inherit "room/room";

reset(arg) {
set_not_out(1);
add_exit("west","/wizards/tiergon/dungeon/4xroad");
add_exit("southeast","/wizards/tiergon/dungeon/d2");
  short_desc = "An abandoned mining tunnel";
  long_desc = "The gray walls are covered with a thick layer of dust that makes you cough.\n"+
              "The tunnel feels surprisingly cool.\n";
}

