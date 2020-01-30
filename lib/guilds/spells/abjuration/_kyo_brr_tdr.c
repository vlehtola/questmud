// Changed spell name from remove protections to purge by C. 20051028
// Idea: removes ALL magic effects on the target (both good and bad)

resolve(int bonus, string target) {
        object ob,sphere;
        string target2;
        if(target) ob = present(target, environment(this_player()));
        if (!ob) {
                write("No such person here.\n");
                return 1;
        }
        if(!living(ob)) {
			write(target+" is not a valid target.\n");
			return 1;
		}
		target2 = target;
		if(ob == this_player()) {
			target = "yourself";
			target2 = this_player()->query_objective()+"self";
		}

        write("You cast purge at "+target+".\n");
        say(this_player()->query_name()+" purges all magic effects from "+target2+".\n",ob);
        tell_object(ob, "All the magic effects affecting you are purged by "+this_player()->query_name()+".\n");
        ob->end_sphere_of_protection();
        ob->end_protection();
        ob->end_stone_skin();
        ob->end_stun_res();
        ob->end_vulnerability();
        ob->end_vulnerability();
        ob->end_shield();
        ob->end_haste(1); /* no ep loss  //Celtron */

	// Added by C. removes magic bane effect & 2 stat boosts
        ob->end_stat_boost();
        ob->end_stat_boost();

	sphere = present("magic_bane", ob);
	if(sphere) sphere->end_magic_bane();

	// the following spell effects should be modified so that they work WITHOUT shadow()! C
	ob->end_anticounter();
        ob->end_antireflect();
        ob->end_mana_shield();
        return 1;
}
