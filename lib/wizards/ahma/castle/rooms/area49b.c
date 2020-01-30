inherit "room/room";

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area49");
  add_exit("portal", "/wizards/manta/hill/room10");
  short_desc = "Portal room";
  long_desc =  "The source of the mystical glow.\n" + 
               "The room is pulsating in bright violet. The red part of the color comes\n" + 
               "from the glowing stones in the walls. The blue, for its part, comes from\n" + 
               "an ellipse-shaped glowing matter. It must be a portal of some sort. All\n" + 
               "in all, the room is very small, just the glowing portal and a little free\n" + 
               "space in its surroundings. The ceiling is only like seven feet high. The\n" + 
               "floor behind the portal is dusty, unlike on front of the portal, which\n" + 
               "means that this device has been recently used, a lot.\n";
  items = allocate(2);
  items[0] = "portal";
  items[1] = "A portal shining in light blue glow. It is ellipse-shaped and some white\n" + 
             "particles of energy move inside the sphere. There are no signs in sight,\n" + 
             "which would give a clue, where this portal will teleport the one who enters\n" + 
             "it. You have a strange feeling that you have seen a portal alike somewhere\n" + 
             "else before";

  set_not_out(1);
}

props() {
  property = ({"no_kill", "no_skill", "no_spell", "no_summon"});
  return;
}