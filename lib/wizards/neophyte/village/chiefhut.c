inherit "room/room";
object chief;

reset(arg) {
        if(!chief) {
                chief = clone_object("/wizards/neophyte/village/monst/chief");
                move_object(chief, this_object());
        }
        if(arg) return;
        short_desc = "An important looking hut";
        long_desc = "This hut looks much more sturdier then others. The walls are made from\n"+
                    "differents sized sticks. A large wooden bed is northern side of hut and it\n"+
                    "looks quite cousy. A small lantern is hanging one of the sticks, bringing\n"+
                    "little light of this small hut. The ceiling is much higher here then others\n"+
                    "huts. The grounds is made of small stones and it feels quite cold.\n";
        set_not_out(1);
        set_light(2);
            items = allocate(6);
		            items[0] = "bed";
		            items[1] = "The bed looks quite worn and fragile when looking closer";
		            items[2] = "lantern";
		            items[3] = "The lantern looks full of oil and it is burning with small flame inside";
		            items[4] = "stones";
                    items[5] = "The floor feels quite cold when stepped on";
add_exit("west", "room2");
add_exit("east", "room6");
add_exit("southwest", "room3");
add_exit("southeast", "room5");
  }
