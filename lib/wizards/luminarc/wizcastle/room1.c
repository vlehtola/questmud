inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/luminarc/wizcastle/room0");
  add_exit("north","/wizards/luminarc/wizcastle/northhall");
 add_exit("east","/wizards/luminarc/wizcastle/easthall");
add_exit("west","/wizards/luminarc/wizcastle/westhall"); 
short_desc = "Entrance hall";
long_desc="This is the entrance hall of the castle. Walls are equipped with\n"+
          "several pictures of some strange old man. Maybe in the past this\n"+ 
          "place was something great, but the time has done its job and the\n"+ 
          "greatest glory of this place is lost forever. In the north there\n"+ 
          "are big marble stairs leading up.\n"; 
  property = allocate(1);
  set_light(3);
ob = clone_object("/wizards/luminarc/wizcastle/humans/servant");
move_object(ob, this_object());
items = allocate(4);
items[0]="pictures";
items[1]="As you take the closer look at the pictures you notice that they are pictures of some old gnomish man with long beard";
}







