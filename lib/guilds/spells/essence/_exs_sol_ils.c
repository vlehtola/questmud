resolve(bonus, target, caster_ob) {
    int time;
    object ob;
    if (!target) {
	tell_object(caster_ob, "You have to give a name for the illusion.\n");
	return 1;
    }
    tell_object(caster_ob, "You create an illusion named '"+target+"'.\n");
    tell_room(environment(caster_ob),caster_ob->query_name()+" creates an illusion.\n", ({caster_ob}));
    ob = clone_object("/guilds/spell_obj/illusion");
    move_object(ob,caster_ob);
    time = bonus * 10;
    ob->start(target,time);
}
