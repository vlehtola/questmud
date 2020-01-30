inherit "room/room";

reset(arg) {
        if(arg) return;
        short_desc = "The wizards guildhall";
        long_desc = "This is the guildhall of the wizards of Questmud.\n";
        set_light(3);
        property = ({ "no_summon", });

        if (!present("plaque")) {
                move_object(clone_object("/obj/wizplaqu"), this_object());
        }
        add_exit("north","/world/city/inn");
        add_exit("job","/room/job_room");
        add_exit("event","/room/event_room");
        add_exit("cs","/world/city/cs");
}
