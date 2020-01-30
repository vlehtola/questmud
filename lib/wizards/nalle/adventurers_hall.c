inherit "room/room";

int i;
object board;

reset(status arg) {

  if(arg) return;
  short_desc = "Adventurers hall",
  long_desc =
"The Adventurers hall deserves it's reputation as traveller's favorite\n"+
"resting place. A fireplace is warming the room. Staying here will certainly\n"+
"help you to recover faster.\n"+
"Available commands:\n\n"+
" 'lead' to try to lead a race.\n\n";
/*" 'quest pay' to halve the cost of the next level with quest points.\n"+
" 'quest cost' to see how many quest points halving the cost of next level
uses.\n\n";*/

  add_exit("east", "/world/city/inn");
  add_exit("south", "/obj/wish_room");
  if(!i) {
    call_out("tick", 12);
    i = 1;
  }

  move_object(clone_object("/daemons/expplaque"), this_object());
  move_object(clone_object("/daemons/vboard"), this_object());

  set_not_out(1);
  set_light(3);
  property = allocate(4);
  property[0] = "no_summon";
  property[1] = "no_kill";
  property[2] = "no_skill";
  property[3] = "no_spell";
}

tick() {
  object ob;
  int i;
  tell_room(this_object(), "The fireplace warms you comfortably.\n");
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(ob[i]&&living(ob[i])) {
        ob[i]->add_hp(40);
	ob[i]->add_sp(40);
	ob[i]->add_ep(40);
    }
    i += 1;
  }
  call_out("tick", 30);
}  


init() {
  ::init();
  add_action("lead", "lead");
/*  add_action("quest", "quest"); */
  add_action("south","south");
}

lead() {
   call_other("/daemons/leader_d","new_leader");
   return 1;
}

quest(str) {
   int num,cost;

   if (str == "pay") {
	num = this_player()->query_level() + 1;
	if (this_player()->query_level_advance()) {
	   write("You are all ready advancing a level.\n");
	   return 1;
	}
	if (this_player()->query_level_paid()) {
	   write("You already have payed for this level.\n");
	   return 1;
	}
	cost = num / 4 + 1;
	if (this_player()->query_quest_points() < cost) {
	   write("You don't have enough quest points.\n");
	   return 1;
	}
	this_player()->reduce_quest_points(cost);
	this_player()->set_level_paid(1);
	write("You pay for level "+num+" with "+cost+" quest points.\n");
	return 1;
   }
   if (str == "cost") {
	num = this_player()->query_level() + 1;
	cost = num / 4 + 1;
	write(
"Halving the experience cost of level costs "+cost+" quest points.\n");
	write(
"You have "+this_player()->query_quest_points()+" quest points.\n");
	return 1;
   }
   write("Use 'quest pay' or 'quest cost'.\n");
   return 1;
}

south() {
  if (this_player()->query_level() < 10) {
	write("You have to be atleast level 10 to enter that place.\n");
	return 1;
  }
}
