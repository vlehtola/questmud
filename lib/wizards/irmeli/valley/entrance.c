inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("portal", "/wizards/irmeli/valley/entrance2.c");
  add_exit("south", "out: 47 63");
  add_exit("north", "out: 47 63");
  add_exit("west", "out: 47 63");
  add_exit("east", "out: 47 63");

  short_desc = "A ancient stone circle";
  long_desc = "You are standing in the middle of strange, ancient stone circle.\n"+
              "There are nine stones and they are placed symmetrically in a\n"+
              "circle around a large flat stone. You can feel a strong\n"+
              "presence of magic.\n";

    items = allocate(4);
    items[0] = "stones";
    items[1] = "Stones are forming a circle around a flat stone";
    items[2] = "stone";
    items[3] = "A large flat stone, inside the circle of nine stones";

call_other("/wizards/irmeli/valley/virtual_map.c", "start_map");
}
