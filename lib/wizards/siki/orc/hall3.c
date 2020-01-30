inherit "room/room";

reset(arg) {

  add_exit("east","/wizards/siki/orc/hall2");
  add_exit("southwest","/wizards/siki/orc/hall4");
  set_not_out(1);
  set_light(0);

  short_desc = "Long hallway";
  long_desc =
"A dark and humid tunnel leading into the heart of the mountain.\n"+
"The cold stone walls are full of small holes and mining marks.\n"+
"Cold water drips from the ceiling which makes the whole ground\n"+
"wet, destroying all the footprints.\n";


 items = allocate(8);
 items[0] = "walls";
 items[1] = "Cold stone walls full of small holes and mining marks";
 items[2] = "holes";
 items[3] = "Small holes on the walls, probably formed by dripping water";
 items[4] = "ground";
 items[5] = "The ground is all wet and muddy. Old footprints are filled with water\n"+
            "and the forms aren't sharp";
 items[6] = "footprints";
 items[7] = "Footprints with broken forms and full of muddy water. It is impossible to\n"+
            "say what has left them";
}
