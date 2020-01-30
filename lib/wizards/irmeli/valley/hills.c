inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Hills";
  long_desc = "A small hill rises among the swaying cornfield. You are\n"+
              "standing on the top of the hill. The surrounding rocky\n"+
              "mountains are rising to the sky, everywhere around you.\n"+
              "This must be the highest place in here, which can be\n"+
              "reached.\n";
}
reset(arg) {
  ::reset(arg);
  if(arg) return;
  if(!present("scarecrow") && !random(1)) {
    move_object(clone_object("/wizards/irmeli/valley/monsters/scarecrow"), this_object());
  }
}

