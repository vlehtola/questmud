inherit "obj/monster";

reset(arg) {
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(15);
    set_exp(query_exp()/2);
    set_name("tiefling");
    set_race("demon");
    set_alias("woman");
    set_short("A beautiful woman with whiteless eyes");
    set_long("The woman is very beautiful indeed, with luscious blood-red lips and hair that looks like black silk. It's a real pity that her all-black eyes make her look somehow 'wrong'...\n");
    set_aggressive(1);
    set_al(-40);
    set_gender(2);
}


catch_tell(str) {
    string tmp1,tmp2;
    object ob;
    if (sscanf(str, "%s leaves %s", tmp1, tmp2) == 2) {
        ob = find_player(lower_case(tmp1));
        if (!ob) { return; }
        call_out("move_to",1,ob);
    }
} 

move_to(ob) {
        move_player("after " + ob->query_name(), environment(ob));
        attack_object(ob);
}
   
/* Sets some variables in the ant queen so a new small ant can be born. */

monster_died() {
    object ob;
    ob = find_object("/wizards/tiergon/monsters/bccmage");
    if (!ob) { return; }
    ob->reduce_number();
}
