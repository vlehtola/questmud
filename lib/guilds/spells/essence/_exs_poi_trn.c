/* create_scroll */
resolve(bonus,target) {
	object ob;
	int y, x;
	if(!target) { tell_object(caster_ob, "Cast at what?\n"); return 1; }
	ob = present(target, environment(caster_ob));
	if(!ob) { tell_object(caster_ob, "No such thing present.\n"); return 1; }
	if(ob->query_npc()) { tell_object(caster_ob, "This spell works only at players.\n"); return 1; }
	if(ob->query_wiz()) { tell_object(caster_ob, "This spell don't work on wizards.\n"); caster_ob->reduce_hp(caster_ob->query_hp()); return 1; }
	if(!living(ob)) { tell_object(caster_ob, "Try casting at living players.\n"); return 1; }

	y = random(100)+100;
	x = random(100)+100;
	if(!call_other("room/out/outmap", "query_room", y,x)) { resolve(bonus,target); return 1; }
	ob->move_player("virtual /room/out/outmap "+y+" "+x+"");
	tell_object(caster_ob, "You banish "+ob->query_name()+".\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+" banish "+ob->query_name()+".\n", ({caster_ob}));
    tell_object(ob, caster_ob->query_name()+" banish you!\n");
    return 1;
}
