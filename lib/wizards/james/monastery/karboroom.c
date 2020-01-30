
#include "dir.h"
inherit "room/room";
int arpo;
string who;

reset(arg)
{
  if(!arg)
  {
    short_desc = "A small chamber";
    long_desc = "\n";
//    add_exit("south",DIR+"room_10_4.c");
    set_light(1);
//    move_object(clone_object(DIR+"karbo"),this_object());
  }
}

init() {
::init();
add_action("south","south");
add_action("push","push");
}

south()
{
	arpo=random(100);
	if(arpo<50) {
		write("You try to squeeze yourself into the next room but get stuck!\n");
		say(this_player()->query_name()+" gets stuck and blocks the exit!\n");
		who=this_player()->query_name();
		remove_action("south");
//		add_action("push","push");
		return 1;
	}
	write("You squeeze yourself through the opening.\n");
	say(this_player()->query_name()+" squeezes "+this_player()->query_objective()+
	      "self through the opening.\n");
	move_object(this_player(),DIR+"room_10_4.c");
	return 1;
}

push(str)
{
	if(!str) {
		write("Push who?\n");
		return 1;
	}
	if(str==lower_case(who) && this_player()->query_name()==who) {
		write("Push yourself? Forget it.\n");
		return 1;
	}
	if(str==lower_case(who) && this_player()->query_name()!=who) {

	arpo=random(100);
	if(arpo<40) {
		write("You try and try but can't push "+who+" through the opening.\n");
		say(this_player()->query_name()+" fails to push "+who+" through the opening.\n");
		return 1;
	}
	write("You push "+who+" through the opening.\n");
	say(this_player()->query_name()+" pushes "+who+" through the opening.\n");
	move_object(find_player(lower_case(who)),DIR+"room_10_4.c");
	remove_action("push");
	add_action("south","south");
	return 1;
	}
}
