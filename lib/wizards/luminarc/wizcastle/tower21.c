inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("up","/wizards/luminarc/wizcastle/tower23");
  add_exit("down","/wizards/luminarc/wizcastle/upnorth1");   
short_desc = "Ladders";
  
  long_desc = "Small wooden ladders continue up and down from here.\n"+
              "There are no light sources at all. Cold wind is blowing from\n"+ 
              "the up. Ladders are making weird noise while you step on them.\n";
  property = allocate(1);
  set_light(1);
  ob = clone_object("/wizards/luminarc/wizcastle/humans/repair.c");
  move_object(ob, this_object());

}


