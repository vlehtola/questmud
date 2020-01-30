inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("up","/wizards/luminarc/wizcastle/tower22");
  add_exit("down","/wizards/luminarc/wizcastle/tower21");   
short_desc = "Ladders";
  
long_desc = "Small wooden ladders continues to up and down from here.\n"+
              "There are no light sources at all cold wind is blowing from\n"+
              "the up. Ladders are making weird noise while you step on them\n";
  
set_light(1);
  ob = clone_object("/wizards/luminarc/wizcastle/humans/young.c"); 
  move_object(ob, this_object());
  ob = clone_object("/wizards/luminarc/wizcastle/humans/young.c");
  move_object(ob, this_object());

}

