inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/tunnels/virtual_tunnel_map";
  short_desc = "A narrow passage";
  long_desc = "A very narrow passage. There is barely room enough for\n"+
              "you to walk in here.\n";
}

reset() {
  ::reset();
  if(!present("rat") && (random(8) >= 2)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/rat"), this_object());
  }
  if(!present("rat") && (random(8) >= 2)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/rat"), this_object());
  }
  if(!present("rat") && (random(8) >= 2)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/rat"), this_object());
  }
  if(!present("rat") && (random(8) >= 2)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/rat"), this_object());
  }
  if(!present("rat") && (random(8) >= 2)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/rat"), this_object());
  }
}