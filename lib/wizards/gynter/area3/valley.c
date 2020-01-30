inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/area3/virtual_map";
  short_desc = "A narrow passage";
  long_desc = "This is a narrow passage that goes through the mountains.\n"+
              "It is following an old creek that has long since dried out,\n"+
              "and has left this well preserved path.\n";
}

reset() {
  ::reset();
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
  if(!present("troll") && !random(6)) {
    move_object(clone_object("/wizards/gynter/area3/troll"), this_object());
  }
}

