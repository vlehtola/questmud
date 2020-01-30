inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/area3/virtual_map";
  short_desc = "Plains";
  long_desc = "Huge rolling plains that is covered with tall grass.\n"+
              "It is about waist height and could hide anything!\n";
}

reset() {
  ::reset();
  if(!present("pixie") && !random(3)) {
    move_object(clone_object("/wizards/gynter/area3/pixie"), this_object());
  }
  if(!present("pixie") && !random(4)) {
    move_object(clone_object("/wizards/gynter/area3/pixie"), this_object());
  }
  if(!present("pixie") && !random(3)) {
    move_object(clone_object("/wizards/gynter/area3/pixie"), this_object());
  }
  if(!present("pixie") && !random(4)) {
    move_object(clone_object("/wizards/gynter/area3/pixie"), this_object());
  }
}

