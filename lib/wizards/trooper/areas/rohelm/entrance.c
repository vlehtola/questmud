inherit "room/room";
string aika = "/obj/timer"->query_time_of_day(); 

reset(arg) {
  if(aika == "midday" || aika == "morning" || aika == "evening") { remove_exit("north"); }
  if (arg) return; 



add_exit("south", "kartalle");
short_desc = "Entrance to the city of Rohelm";
long_desc = "A massive gate blocks your entrance and view to this great city.\n"+
	   "The walls surrounding the city are very tall and made of stone.\n"+
	   "No sounds are coming from behind the gate and no particular scent.\n"+
	   "is smelling. A lots of footsteps have been pressed on grounds.\n";

  items = allocate(4);
  items[0] = "footsteps";
  items[1] = "A lots of footsteps lead inside the city but only a few are coming out";
  items[2] = "gate";
  items[3] = "This massive gate is solid metal and there's no way getting through it";

}
init() {
::init();
add_action("knock", "knock");
}

knock(str) {
   if(str == "gate") {
      if(aika == "midnight" || aika == "night") {
	add_exit("north","/wizards/trooper/areas/rohelm/r1.c");
	  write("The gate opens before you as you knock it!\n");
funktio_sulje_ovi();
return 1;
}
if(aika == "midday" || aika == "evening" || aika == "morning"){
remove_exit("north");
  write("You knock and knock but nothing happens.\n");
    return 1;
}
}
}
funktio_sulje_ovi() {
	write("The gate closes after being open for a while.\n");
remove_exit("north");
}
