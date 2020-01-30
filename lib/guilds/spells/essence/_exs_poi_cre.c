/* create_scroll */
resolve(bonus, target, caster_ob) {
	object ob;
	ob = clone_object("/wizards/neophyte/scroll");
	move_object(ob, caster_ob);
	tell_object(caster_ob, "You create a empty scroll.\n");
    tell_room(environment(caster_ob),caster_ob->query_name()+" creates a empty scroll.\n", ({caster_ob}));
    return 1;
}
