inherit "room/room";

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/forest/for17");
  add_exit("northeast", "/wizards/ahma/orc/village/vil15");
  add_exit("southeast", "/wizards/ahma/orc/village/vil13");
  short_desc = "Entrance to village Nehelam";
  long_desc = "########### Sralk and Galor streets begin from here. The Sralk street leads to\n" + 
              "#    /    # northeast and Galor street to southeast. To west is the entrance\n" + 
              "# --*     # leading into the forest which is surrounding this village. The\n" + 
             "#    \\ H  # forest seems to be mainly consisted of green deciduous trees. Lots\n" + 
              "########### of animal voices can be heard coming from behind the trees.\n";
}

init() {
  ::init();
  add_action("map", "map");
  if(present("walkeri", this_object())) {
  call_other(present("walkeri", this_object()), "checkroom");
  }
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}
