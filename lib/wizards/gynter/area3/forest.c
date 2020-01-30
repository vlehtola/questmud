inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/area3/virtual_map";
  short_desc = "Elder Forest";
  long_desc = "A HUGE forest with enormous trees.\n"+
              "The trees are about thirty meters tall and it's majestic\n"+
              "trunks is more than eight meters around.\n";
}

reset() {
  ::reset();
  if(!present("elf") && !random(4)) {
    move_object(clone_object("/wizards/gynter/area3/elf"), this_object());
  }
  if(!present("elf") && !random(4)) {
    move_object(clone_object("/wizards/gynter/area3/elf"), this_object());
  }
  if(!present("elf") && !random(4)) {
    move_object(clone_object("/wizards/gynter/area3/elf"), this_object());
  }
}

