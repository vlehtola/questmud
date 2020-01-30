inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/area3/virtual_map";
  short_desc = "Passage";
  long_desc = "A very narrow passage through the mountains.\n"
              "It is the only way of reaching the Oasis.\n"+
              "But it doesn't look safe.\n";
}
reset() {
  ::reset();
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
}
