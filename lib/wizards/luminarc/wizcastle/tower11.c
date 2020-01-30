inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("up","/wizards/luminarc/wizcastle/tower12");
  add_exit("down","/wizards/luminarc/wizcastle/upeast2");   
short_desc = "Ladders";
  
 long_desc = "Small wooden ladders continue to up and down from here.\n"+
              "Cold wind is blowing from up and it has extinguished all\n"+
              "the torches. Ladders are making weird noises while stepped\n"+ 
              "on.\n";

  set_light(1);
ob = clone_object("/wizards/luminarc/wizcastle/humans/repair.c");
move_object(ob, this_object());

}

