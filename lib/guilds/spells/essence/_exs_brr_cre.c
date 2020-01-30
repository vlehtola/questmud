resolve(bonus, target, caster_ob) {
    object ob;
    if(!caster_ob)caster_ob=this_player();
    ob = clone_object("guilds/spell_obj/light.c");
    move_object(ob,caster_ob);
    bonus = bonus * 2;
    if (bonus > 400) {
	ob->start(-3,bonus);
	tell_object(caster_ob, "You create a strong ball of darkness.\n");
	tell_room(environment(caster_ob), caster_ob->query_name()+" creates a strong ball of darkness.\n", ({ caster_ob }));
	return 1;
    }
    if (bonus > 200) {
	ob->start(-2,bonus);
	tell_object(caster_ob, "You create a ball of darkness.\n");
	tell_room(environment(caster_ob), caster_ob->query_name()+" creates a ball of darkness.\n", ({ caster_ob }));
	return 1;
    }
    ob->start(-1,bonus);
    tell_object(caster_ob, "You create a weak ball of darkness.\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+" creates a weak ball of darkness.\n", ({ caster_ob }));
}
