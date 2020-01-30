inherit "room/room";
inherit "room/door";
int door_number;
reset(arg) {
          if(!present("undead")) {
            move_object(clone_object("/wizards/neophyte/city/monst/undead"),
            this_object());
        }
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A small corridor";
long_desc =  "The corridor ends in here. A strong light is coming from slots\n"+
             "in the door. A few rags are stuffed in the holes of door. Windows\n"+
             "are dirty and couple of them are broken.\n";

add_exit("east","corridor15");

  property = allocate(1);
  property[0] = "no_summon";
  door_reset();
  door_number = 1;
  set_door_label("iron door", 1);
  set_door_dir("up", "/wizards/neophyte/city/lighthouse/corridor17", 1);
  set_door_link("/wizards/neophyte/city/lighthouse/corridor17", 1);
  set_door_code("123", 1);
  set_locked(1, 1);
}


init() {
  ::init();
  door_init();
}

