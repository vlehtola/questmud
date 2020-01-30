inherit "obj/monster";

        reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_race("troll"); 
	set_level(70);
        set_name("guard");
        set_alias("troll");
        set_alias("kluh");
        set_short("Kluh the troll stands watch here");
        set_long("Tamed by the dwarven death knight, Kluh was found\n"+
                 "somewhere deep in the caves of the southern mountains\n"+
                 "He has huge hands that look like they could grab you\n"+
                 "and throw you to kingdom come.\n");
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

        tell_object(target,"Kluh GRABS YOU in his ARMS and THROWS YOU DOWN from the bridge!\n");
        call_other(fall,"kuolema",5,target);
        move_object(target,fall);
        tell_room(room,"Kluh GRABS "+target->query_name()+" in his ARMS and THROWS "+target->query_name()+" DOWN from the bridge!\n");
}

status filtteri(object ob) {
        if(living(ob) && !ob->query_npc()) return 1;
        return 0;
}
