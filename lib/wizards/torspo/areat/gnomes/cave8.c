inherit "room/room";

reset(arg) {
 if(!present("miner")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/miner1"), this_object());
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/miner1"), this_object());
 }

  if(arg) { return; }
  add_exit("northwest", "/wizards/torspo/areat/gnomes/cave14.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/city3.c");

  set_not_out(1);
  set_light(2);
  short_desc = "gnomish city";
  long_desc = "This is part of the main tunnel. To the east it leads downwards to the\n"+
              "gnomish city. Small stalagmites decorate the area and sound of dripping\n"+
              "water echoes all over this place. Small cave-in has buried part of the\n"+
              "tunnel on the western wall and there is some mining equipment and one mining\n"+
              "cart left here.\n";
  items = allocate(10);
  items[0] = "stalagmites";
  items[1] = "Small, beautiful stalagmites. They have formed by dripping water";
  items[2] = "cave-in";
  items[3] = "Part of the western wall has collapsed due to small earthquake";
  items[4] = "western wall";
  items[5] = "Part of the western wall has collapsed due to small earthquake";
  items[6] = "equipment";
  items[7] = "Some picks and hammers lie in disorder on the ground";
  items[8] = "cart";
  items[9] = "A mining cart. It is made of hard steel and moves on tracks. Heavy rocks\n"+
             "are carried away with it";
}
