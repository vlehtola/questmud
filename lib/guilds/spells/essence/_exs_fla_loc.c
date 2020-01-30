/* Banish */
resolve(bonus,target, caster_ob) {
        int mastery, x, y;
        string vroom;
        object ob;
        vroom = "/room/out/outmap";
        if(!caster_ob)caster_ob=this_player();
    if(!target) { tell_object(caster_ob, "Cast at what?\n"); return 1; }
    ob = present(target, environment(caster_ob));
    if(caster_ob->query_npc()) ob = find_player(target);
    if(!ob) { tell_object(caster_ob, target+" is not valid target.\n"); return 1; }
    if(ob->query_wiz()) { tell_object(caster_ob, "Now you done it.\n"); tell_object(ob, caster_ob->query_name()+" tries to banish you!\n"); caster_ob->death(); return 1; }
    if(ob->query_npc()) { tell_object(caster_ob, "This spell works only at players.\n"); return 1; }
    if (present("teleport lock", ob)) { tell_object(caster_ob, "You fail to banish "+ob->query_name()+".\n"); return 1; }
    if(ob == caster_ob) { tell_object(caster_ob, "You can't banish yourself.\n"); return 1; }
    if(!living(ob)) { tell_object(caster_ob, "This spell works only at players.\n"); return 1; }
    x = random(300);
    y = random(300);
    if(caster_ob->query_wiz()) { tell_object(caster_ob, "X:"+x+" Y:"+y+"\n"); }
    if(vroom->check_no_walk(vroom->get_map_char(x, y))) {
                resolve(bonus,target, caster_ob);
                return 1;
    }
    tell_object(caster_ob, "You banish "+ob->query_name()+".\n");
    tell_object(ob, "You have been banished by "+caster_ob->query_name()+".\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+" banishes "+ob->query_name()+".\n", ({caster_ob }));
    ob->move_player("XX#virtual /room/out/outmap "+x+" "+y);
    return 1;
}
