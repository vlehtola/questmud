inherit "room/room";
reset(arg) {
          if(!present("undead")) {
            move_object(clone_object("/wizards/neophyte/city/monst/undead"),
            this_object());
        }
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A private room of drake";
long_desc =  "This is the private resting place of drake. A large table\n"+
             "is center of the room and some important looking papers are\n"+
             "on the table. A cosy looking bed is on the one corner and\n"+
             "nicely decorated wooden closet in the other. A small oil lamp\n"+
             "is burning next to the bed.\n";

add_exit("north","corridor11");

  property = allocate(1);
  property[0] = "no_summon";
  }

