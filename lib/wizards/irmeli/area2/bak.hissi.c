inherit "room/room";

int location,direction;

reset(arg) {
   short_desc = "In the elevator";
   long_desc = "You are standing on the elevator platform. The old elevator is brittle like any\n"+
                 "other old lift. There are no walls in it because miners needed\n"+
                 "all space to the goods and it is lighter without the walls.\n";
   set_not_out(1);
   add_exit("jump", "wizards/irmeli/area2/ruum28.c");
   set_light(3);
}

start_elevator() {
   location = 1;   
   add_exit("south", "wizards/irmeli/area2/ruum6.c");
   call_other("wizards/irmeli/area2/ruum6.c", "add_exit",
        "north", "wizards/irmeli/area2/hissi.c");
   call_out("change_pos",30);
}

change_pos() {
   if (!present("hobbit", find_object("wizards/irmeli/area2/ruum6"))) {
	call_out("change_pos", 30);
	return 1;
   }
   tell_room("wizards/irmeli/area2/ruum6",
	"The hobbit starts operating the winch.\n");
   if (location == 1) {
        tell_room(this_object(), "The elevator starts moving downwards.\n");
	tell_room("wizards/irmeli/area2/ruum6",
		"The elevator starts moving downwards.\n");
        call_other("wizards/irmeli/area2/ruum6.c", "remove_exit", "north");
        remove_exit("south");
        call_out("real_move", 10);
   }
   if (location == 3) {
        tell_room(this_object(), "The elevator starts moving upwards.\n");
	tell_room("wizards/irmeli/area2/ruum15",
		"The elevator starts moving upwards.\n");
        call_other("wizards/irmeli/area2/ruum15.c", "remove_exit", "south");
        remove_exit("north");
        call_out("real_move", 10);
   }
   if (location == 2) {
        if (direction == 1) {
           tell_room(this_object(), "The elevator starts moving downwards.\n");
	   tell_room("wizards/irmeli/area2/ruum7",
		"The elevator starts moving downwards.\n");
        }
        if (direction == 3) {
           tell_room(this_object(), "The elevator starts moving upwards.\n");
	   tell_room("wizards/irmeli/area2/ruum7",
		"The elevator starts moving upwards.\n");
        }
        call_other("wizards/irmeli/area2/ruum7.c", "remove_exit", "north");
        remove_exit("south");
        call_out("real_move", 10);
   }
}

real_move() {
   tell_room("wizards/irmeli/area2/hissi.c", "The elevator stops moving.\n");
   if (location == 1 || location == 3) {
	if (location == 1) {
	  tell_room("wizards/irmeli/area2/ruum7",
		"The elevator arrives from the up.\n");
	}
	if (location == 3) {
	  tell_room("wizards/irmeli/area2/ruum7",
		"The elevator arrives from the down.\n");
	}
        call_other("wizards/irmeli/area2/ruum7.c", "add_exit",
                "north","wizards/irmeli/area2/hissi.c");
        add_exit("south", "wizards/irmeli/area2/ruum7.c");
        direction = location;
        location = 2;
        call_out("change_pos", 30);
        return 1;
   }
   if (location == 2) {
        if (direction == 3) {
	   tell_room("wizards/irmeli/area2/ruum6",
		"The elevator arrives from the down.\n");
           call_other("wizards/irmeli/area2/ruum6.c", "add_exit",
                "north","wizards/irmeli/area2/hissi.c");
           add_exit("south", "wizards/irmeli/area2/ruum6.c");
           location = 1;
        }
        if (direction == 1) {
	   tell_room("wizards/irmeli/area2/ruum15",
		"The elevator arrives from the up.\n");
           call_other("wizards/irmeli/area2/ruum15.c", "add_exit",
                "south","wizards/irmeli/area2/hissi.c");
           add_exit("north", "wizards/irmeli/area2/ruum15.c");
           location = 3;
        }
        call_out("change_pos", 30);
        return 1;
   }
}

init() {
   ::init();
   add_action("jump","jump");
}

jump() {
   int dama;
   write("You jump in the shaft!\n");
   write(".. and hit the bottom, ");
   this_player()->lited("OUCH");
   write("!\n");
   dama = random(10) + 10;
   this_player()->reduce_hp(dama);
}
