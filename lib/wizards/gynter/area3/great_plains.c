inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/area3/virtual_map";
  short_desc = "Great Plains";
  long_desc = "Extremely short grass coveres the ground.\n"+
              "The grass looks like it has been grazed.\n";
}

reset() {
  ::reset();
  if(!present("rabbit") && !random(3)) {
    move_object(clone_object("/wizards/gynter/area3/rabbit"), this_object());
  }
  if(!present("rabbit") && !random(3)) {
    move_object(clone_object("/wizards/gynter/area3/rabbit"), this_object());
  }
  if(!present("rabbit") && !random(3)) {
    move_object(clone_object("/wizards/gynter/area3/rabbit"), this_object());
  }
  if(!present("rabbit") && !random(3)) {
    move_object(clone_object("/wizards/gynter/area3/rabbit"), this_object());
  }
}

