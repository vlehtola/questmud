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

        add_exit("west","/wizards/jenny/linnake/huoneet/prison5.c");
        add_exit("northwest","/wizards/jenny/linnake/huoneet/prison8.c");
        add_exit("north","/wizards/jenny/linnake/huoneet/prison9.c");        
        add_exit("south","/wizards/jenny/linnake/huoneet/prison3.c");
        add_exit("southwest","/wizards/jenny/linnake/huoneet/prison1.c");

        short_desc = "You are walking in a prison complex";
        long_desc = "You are walking in a prison complex and you see guards dragging some\n"+
                    "dead prisoner away from a cell. Some rats are wildly running on the\n"+
                    "floor. All cell doors are made of iron and they seem to be\n"+
                    "very good quality\n";

        door_reset();
        set_door_label("Shiny prison cell door",1);
        set_door_dir("east", "/wizards/jenny/linnake/huoneet/jail2.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/jail2.c",1);
        set_door_code("571", 1);
        set_locked(1, 1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
