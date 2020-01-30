inherit "obj/monster";

        reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(70);
        set_name("guard");
        set_alias("dwarf");
        set_alias("arukhelban");
        set_short("Arukhelban the dwarf stands watch here");
        set_long("Arukhelban does not quite look like your average dwarf would.\n"+
                 "He has no beard, a sign that he's been outcast from a former\n"+
                 "clan, and his muscles are bulging.\n");
        set_race("dwarf");
        set_block_dir("west");
        set_special(10);

}


special_move() {
        object players, target, room;
        int i;
        string fall;

        fall = "/wizards/walla/northern/stuph/fall";
        room = environment(this_object());

        players = all_inventory(room);
        players = filter_array(players, "filtteri");

        i = sizeof(players);

        target = players[random(i)];

        tell_object(target,"Arukhelban throws you down from the bridge!\n");
        call_other(fall,"kuolema",5,target);
        move_object(target,fall);
        tell_room(room,"Arukhelban throws "+target->query_name()+" down from the bridge!\n");
}

status filtteri(object ob) {
        if(living(ob) && !ob->query_npc()) return 1;
        return 0;
}

