
#include "dir.h"
inherit "room/room";
int sc,gc;

reset(arg)
{
  if(!arg)
  {
    short_desc = "A dark room";
    long_desc = "A dark room with high ceiling and dirty walls. Some light shines down from the cracked ceiling. A crack in the north wall shows that there is a large chamber behind it. Some strange symbols have been embedded in the north wall.\n";
    add_exit("south",DIR+"room_10_5.c");
    set_light(1);
    items = allocate(2);
    items[0] = "symbols";
    items[1] = "Two small cross-shaped slots are surrounded by strange symbols";
  }
}

init() {
   add_action("insert","insert");
   ::init();
}

insert(str) {
   if(str!="golden cross" && str!="silver cross") {
	write("Insert what?\n");
	return 1;
   }
   if(str=="silver cross" && sc==0) {
	if(!present("silver cross",this_player()) || sc==1) {
		write("Insert what?\n");
		return 1;
	}
	if(present("silver armband",this_player()) == 0 && present("silver cross",this_player())) {
		write("You start to insert the cross into the slot but a surge of power "+
		      "stings your fingers and disintegrates the cross!\n");
		destruct(present("silver cross",this_player()));
		this_player()->hit_with_spell(100,"physical");
		return 1;
	}
   	if(present("silver armband",this_player()) && present("silver cross",this_player())) {
		write("You insert the cross into the slot. Suddenly your silver armband turns to dust!\n");
		destruct(present("silver cross",this_player()));
//		destruct(present("silver armband",this_player()));
		sc=1;
		if(gc==1 && sc==1) {
			write("The wall divides in the middle and opens a small exit to the north!\n");
			add_exit("north",DIR+"karboroom.c");
			remove_action("insert");
		}
		return 1;
	}
   }

   if(str=="golden cross" && gc==0) {
	if(!present("golden cross",this_player()) || gc==1) {
		write("Insert what?\n");
		return 1;
	}
	if(present("golden armband",this_player()) == 0 && present("golden cross",this_player())) {
		write("You start to insert the cross into the slot but a surge of power "+
		      "stings your fingers and disintegrates the cross!\n");
		destruct(present("golden cross",this_player()));
		this_player()->hit_with_spell(100,"physical");
		return 1;
	}
   	if(present("golden armband",this_player()) && present("golden cross",this_player())) {
		write("You insert the cross into the slot. Suddenly your golden armband turns to dust!\n");
		destruct(present("golden cross",this_player()));
//		destruct(present("golden armband",this_player()));
		gc=1;
		if(gc==1 && sc==1) {
			write("The wall divides in the middle and opens a small exit to the north!\n");
			add_exit("north",DIR+"karboroom.c");
			remove_action("insert");
		}
		return 1;
	}
   }
}
