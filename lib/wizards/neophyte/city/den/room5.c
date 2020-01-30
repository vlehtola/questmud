#include "/wizards/neophyte/city/misc/misc.h"
inherit "room/room";
object rider;
reset(arg) {
               if(!rider) {
                       rider = clone_object(monspath+"wolfrider");
                       move_object(rider, this_object());
       }
        add_exit("southeast","entrance");
short_desc = "Dead end";
long_desc = "The caverns ends suddenly in here looking like it haven't been finished.\n"+
            "On the floor is lots of hay that are piled to remind a bed and small bones\n"+
            "covers the floor. On the wall is torch which brings light to this dark cave.\n";
set_not_out(1);

}


