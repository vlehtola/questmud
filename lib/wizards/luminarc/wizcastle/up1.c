inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("down","/wizards/luminarc/wizcastle/northhall");
  add_exit("east","/wizards/luminarc/wizcastle/upeast1");
  add_exit("west","/wizards/luminarc/wizcastle/upwest1");
  add_exit("north","/wizards/luminarc/wizcastle/mawork");
  short_desc = "Stairs";
long_desc="Second level of the castle looks almost as big as the first level.\n"+
          "The main corridor is leading north to some kind of workroom. Narrow\n"+ 
          "corridor leads to the east and to the west. Lot of torches has been\n"+
          "placed on the walls.\n"; 
  set_light(3);

  ob = clone_object("/wizards/luminarc/wizcastle/humans/pguard.c");
  move_object(ob, this_object());
  ob = clone_object("/wizards/luminarc/wizcastle/humans/pguard.c");
  move_object(ob, this_object());
  ob = clone_object("/wizards/luminarc/wizcastle/humans/pguard.c");
  move_object(ob, this_object());


 

}


