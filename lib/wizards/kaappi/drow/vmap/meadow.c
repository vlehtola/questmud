inherit "room/outroom";

start() {
  mapfile = "/wizards/kaappi/drow/vmap/virtual_map";
  short_desc = "An underground meadow";
  long_desc = "An underground meadow. Some animals\n"+
              "can be seen all around. A green lichen covers\n"+
              "the ground almost everywhere. Some mushrooms\n"+
              "grows here and there. The air is much more\n"+
              "humid than it is in previous tunnels.\n";

}
reset() {
  ::reset();
  if(!present("elukka") && !random(2)) {
  move_object(clone_object("/wizards/kaappi/drow/mobs/elukat"), this_object());
 }
}
