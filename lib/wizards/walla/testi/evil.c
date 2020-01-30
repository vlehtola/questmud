inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(60);
        set_name("monster");
        set_short("The evil monster");
        set_long("A nice little instakill.\n");
        set_special(50);
}


special_move() {
        object players, target, room;
        int i;
        string fall;

        fall = "/wizards/rag/test/fall";
        room = environment(this_object());
        
        players = all_inventory(room);
        players = filter_array(players, "filtteri");
        
        i = sizeof(players);

        target = players[random(i)];

        tell_object(target,"The evil monster throws you down from the bridge!\n");
        call_other(fall,"kuolema",5,target);
        move_object(target,fall);
        tell_room(room,"The evil monster throws "+target->query_name()+" down from the bridge!\n");
}

status filtteri(object ob) {
        if(living(ob) && !ob->query_npc()) return 1;
        return 0;
}

