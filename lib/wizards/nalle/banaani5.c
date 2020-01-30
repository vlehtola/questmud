inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("out","wizards/nalle/workroom");
  short_desc = "The Plankton Bar.";
  long_desc =
"A room where penguins play the xylophone and eat plankton.\n";
}

init() {
    ::init();
   add_action("read", "read");
}

read(str) {
    if (!str) {
        return 0;
    }
   cat(str);
   return 1;
}
