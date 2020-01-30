inherit "room/room.c";

reset(arg) {
  if (arg) return;
  object ob;
  short_desc = "Lattia ruum";
  long_desc = "This is the lattia ruum. Maybe you could blast the floor.\n";
  ob = clone_object("/wizards/onarion/blast_ob.c");
  move_object(ob, this_object());
}


