inherit "room/room";




   reset(arg) {
      if(arg) return;

  add_exit("up","/wizards/siki/island/cave4");
  add_exit("north","/wizards/siki/island/floora2");
  add_exit("east","/wizards/siki/island/floora5");




  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into north and east. The\n"+
              "marks on the cold stone walls are quite new. A set of\n"+
              "tracks fades into the north. A cold breeze from the shaft\n"+
              "chills the air.\n";

  set_not_out(1);

  items = allocate(4);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "tracks";
  items[3] = "A set of iron tracks used for ore wagons";
}
