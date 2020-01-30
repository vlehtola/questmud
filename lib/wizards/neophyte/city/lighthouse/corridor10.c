inherit "room/room";
reset(arg) {
          if(!present("undead")) {
            move_object(clone_object("/wizards/neophyte/city/monst/undead"),
            this_object());
        }
if(arg) return;

set_not_out(1);
short_desc = "A small cleaning closet";
long_desc =  "The ground feels ghastly to step on. In here is too dark\n"+
             "to see any special details, maybe it's because this closet\n"+
             "is storage place of all the cleaning equipment used in the\n"+
             "lighthouse.\n";

add_exit("west","corridor9");

  property = allocate(1);
  property[0] = "no_summon";
}

