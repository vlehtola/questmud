inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("south", "/wizards/kaappi/drow/vmap/virtual_map: 36 16");
  add_exit("southwest", "/wizards/kaappi/drow/vmap/virtual_map: 36 16");
  add_exit("southeast", "/wizards/kaappi/drow/vmap/virtual_map: 36 16");
  add_exit("enter", "/wizards/kaappi/drow/rooms/temple/t1.c");

  short_desc = "A temple of Lloth";
  long_desc = "You are standing in front of the gates which\n"+
              "leads to the temple. There are two gorgeous looking\n"+
              "statues made of black rock. The other one is a\n"+
              "statue of a very beatufil female drow and the another\n"+
              "statue is a huge spider which has a head of an elf.\n";
}
