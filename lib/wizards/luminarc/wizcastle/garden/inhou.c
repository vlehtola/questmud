inherit "room/room";
object monster;
reset(arg) {
  if(arg) return;
  add_exit("out","/wizards/luminarc/wizcastle/garden/house");
  short_desc = "house";
  long_desc="Inside part of the house looks much better than outside part. Small table\n"+
            "has been placed on the middle of the room and comfortable fireplace on\n"+
            "the eastern wall gives almost nice feeling. Only the worn out roof\n"+
            "and the broken windows make this place little spooky. On west side\n"+
            "there is small shelf, which contains different plants and bottles.\n";

 property = allocate(1);
  set_light(3);
     
if (!monster) {
monster = clone_object("/wizards/luminarc/wizcastle/humans/elvar.c");
      move_object(monster, this_object());
}
}

