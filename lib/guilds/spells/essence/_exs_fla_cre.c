resolve(bonus, target, caster_ob) {
    object ob;
    ob = clone_object("guilds/spell_obj/light.c");
    if(!caster_ob)caster_ob=this_player();
    move_object(ob, caster_ob);
    bonus = bonus * 2;
    if (bonus > 400) {
	ob->start(3,bonus);
	tell_object(caster_ob, "You create a strong light ball.\n");
	tell_room(environment(caster_ob), caster_ob->query_name()+" creates a strong light ball.\n", ({caster_ob }));
	return 1;
    }
    if (bonus > 200) {
	ob->start(2,bonus);
	tell_object(caster_ob, "You create a light ball.\n");
	tell_room(environment(caster_ob), caster_ob->query_name()+" creates a light ball.\n", ({caster_ob }));
	return 1;
    }
    ob->start(1,bonus);
    tell_object(caster_ob, "You create a weak light ball.\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+" creates a weak light ball.\n", ({caster_ob }));
}
