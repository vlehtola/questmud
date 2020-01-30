object ob,pot,tgt;
int i;

query_type() { return "witchcraft"; }

get_time() {
    return 7-(this_player()->query_skills("speedcrafting")/20);
}
ep_cost() { return 10-(this_player()->query_skills("speedcrafting")/20); }


resolve_skill(string str) {
    ob = present("corpse", environment(this_player()));
    if(!ob)ob = present("blood", environment(this_player()));
    if(!ob) {
	write("There are no corpse or blood in here.\n");
	return 1;
}
    if(!ob->query_corpse() && !ob->query_blood()) { write("This skill works only at corpse or blood\n"); return 1; }
    pot = present("cauldron", this_player());
    if(!pot) pot = present("cauldron", environment(this_player()));
    if(!pot) {
                write("You need a cauldron where to store the blood.\n"); return 1; }
        i = ob->query_level();
        write("You start sucking the blood from "+str+" and gently pour it inside the cauldron.\n");
        say(this_player()->query_name()+" starts to sucking the blood.\n");
        pot->set_blood(i*5);
        destruct(ob);
        return 1;
}
fail_skill() {
        write("You fail the skill.\n");
        say(this_player()->query_name()+" fails the skill.\n");
}
