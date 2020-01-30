inherit "room/room";

reset(arg) {
set_light(1);
set_not_out(1);
            add_exit("north", "/wizards/aarrgh/nyxi/altar2");
            add_exit("south", "/wizards/aarrgh/nyxi/portal");
            short_desc = "Before the altar";
long_desc =  "This place is the preparation room before the altar of prayers. The room is\n"
             "made of onyx and glitters as the light hits the walls. The flaming portal\n"
             "from outside dimension flickers strongly and it seems the only way out from\n"
             "this place.\n";

items = allocate(4);
  items[0] = "walls";
  items[1] = "The walls are made of pure onyx";


if(!present("demon")) {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/guardian"),
this_object());
}
if(!present("demon 2")) {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/guardian"),
this_object());
}
}

