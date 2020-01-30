
inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
set_light(1);
set_not_out(1);
            add_exit("pool", "/wizards/aarrgh/nyxi/down1");
            add_exit("north", "/wizards/aarrgh/nyxi/volcano8");
            add_exit("east", "/wizards/aarrgh/nyxi/volcano6");
            add_exit("south", "/wizards/aarrgh/nyxi/volcano1");
            add_exit("west", "/wizards/aarrgh/nyxi/volcano4");
            short_desc = "A Sacrificing pool";
long_desc = "A sacrificing pool has been built here. The pool is made of a pure marble and\n"
            "is decorated with human skulls. The pool is not deep and there is something\n"
            "strange in the center of the pool.\n";
items = allocate(4);
  items[0] = "pool";
  items[1] = "This pool is filled with blood";

if(!present("morfeus")) {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/morfeus"),
this_object());
}
}
