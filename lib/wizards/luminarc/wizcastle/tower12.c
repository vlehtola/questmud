inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("down","/wizards/luminarc/wizcastle/tower11");
  short_desc = "Ladders";
  
  long_desc = "This is the top of the tower. Beautiful view is opening from here. The\n"+ 
              "second tower is rising right next to this one. It looks like bit higher\n"+ 
              "than this one. White birds are flying around the castle and singing their\n"+
              "melodic songs, while sound of wild animals echo from the woods.\n";


  property = allocate(1);
  set_light(1);
ob = clone_object("/wizards/luminarc/wizcastle/humans/young.c");
move_object(ob, this_object());
ob = clone_object("/wizards/luminarc/wizcastle/humans/guard.c");
move_object(ob, this_object());

}

