inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("east","/wizards/luminarc/wizcastle/upeast2");
  add_exit("west","/wizards/luminarc/wizcastle/up1");  
short_desc = "Corridor";
  long_desc = "The corridor continues to the west and to the east\n"+
              "from here. Torches on the wall illuminate the corridor\n"+
              "with warm light. Walls are made of black stone of somekind.\n"+
              "Wall is shining while the torches flickers\n";
  property = allocate(1);
  set_light(3);
  ob = clone_object("/wizards/luminarc/wizcastle/humans/wise.c");
  move_object(ob, this_object());

}

