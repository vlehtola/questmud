inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/tunnels/virtual_tunnel_map";
  short_desc = "A large Chamber";
  long_desc = "A very large Chamber. The roof is several hundred feet up.\n"+
              "The chamber is illuminated by some strange mushroom that is\n"+
              "growing on the walls.\n";
}

reset() {
  ::reset();
  if(!present("oldelf") && (random(8) >= 4)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/oldelf"), this_object());
  }
  if(!present("oldelf") && (random(8) >= 4)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/oldelf"), this_object());
  }
}