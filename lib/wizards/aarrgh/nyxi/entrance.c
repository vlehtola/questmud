inherit "room/room";

reset(arg) {
             add_exit("north", "/wizards/aarrgh/nyxi/path");
add_exit("leave", "outmap: 234 121");
short_desc = "Entrance to the Volcano of Xyn";
long_desc =  "A thundering volcano lies ahead. The darkness in this place is somehow\n"
             "different. Something in this place holds the powers of the wicked\n"
             "element. The soil is covered with ashes and dust. A small path\n"
             "covered with blood is leading north.\n";

  items = allocate(4);
  items[0] = "soil";
  items[1] = "The soil is covered with ashes and dust. There are blood everywhere";

  if(!present("soldier")) {
  move_object(clone_object("/wizards/aarrgh/nyxi/mon/soldier"), this_object());
}



}
