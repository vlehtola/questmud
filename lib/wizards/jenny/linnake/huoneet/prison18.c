inherit "room/room";
inherit "room/door";
object monster,monster2;
reset(arg) {

        if(!present("guard")) {
            move_object(clone_object("/wizards/jenny/linnake/mosut/jail_guard.c"), this_object());
        }
        if(!present("guard 2")) {
            move_object(clone_object("/wizards/jenny/linnake/mosut/jail_guard.c"), this_object());
        }
        if(arg) return;

        add_exit("east","/wizards/jenny/linnake/huoneet/prison17.c");         
        add_exit("southeast","/wizards/jenny/linnake/huoneet/prison14.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/prison13.c");

        short_desc = "You are walking in a prison complex";
        long_desc = "You are walking in a prison complex and you see guards dragging some\n"+
                    "dead prisoner away from a cell. Some rats are wildly running on the\n"+
                    "floor. All cell doors are made of iron and they seem to be\n"+
                    "very good quality\n";

        door_reset();
        set_door_label("Shiny prison cell door",1);
        set_door_dir("west", "/wizards/jenny/linnake/huoneet/jail5.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/jail5.c",1);
        set_door_code("571", 1);
        set_locked(1, 1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
