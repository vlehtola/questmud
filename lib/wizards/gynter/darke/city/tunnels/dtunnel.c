inherit "room/outroom";
start() {
  mapfile = "/wizards/gynter/darke/city/tunnels/virtual_tunnel_map";
  short_desc = "A Large Tunnel";
  long_desc = "A very large tunnel. The tunnel could easily be misstaken\n"+
              "for a cave if it wasn't for the way it was shaped.\n"+
              "Two large exits on each side, connecting noumerous of these \"caverns\".\n";
}
reset() {
  ::reset();
  if(!present("dark elf") && (random(8) >= 5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
  if(!present("dark elf") && (random(8) >= 5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
  if(!present("dark elf") && (random(8) >= 5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
}
