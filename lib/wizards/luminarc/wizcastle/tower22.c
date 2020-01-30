inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("down","/wizards/luminarc/wizcastle/tower23");
  short_desc = "Top of the tower";
  
  long_desc = "This is the top of the tower. Beautiful view is opening from here. The smaller\n"+ 
              "tower is rising next to this one. White birds are flying around the castle and\n"+ 
              "singing their melodic songs, while sound of wild animals from the woods echo\n"+
              "to every adventurers ears.\n";
  property = allocate(1);
  set_light(1);
  ob = clone_object("/wizards/luminarc/wizcastle/humans/young.c");
  move_object(ob, this_object());

}



