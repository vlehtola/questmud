/*smallant modded*/
inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    set_level(40);
    //set_exp(query_exp()/2);
    set_name("hellhound");
    set_alias("hound");
    set_short("A drooling hellhound");
    set_long("iivili hellhoundi tab sut\n");
    set_aggressive(1);
}

/* Follows leaving player. */

catch_tell(str) {
    string tmp1,tmp2;
    object ob;
    if (sscanf(str, "%s leaves %s", tmp1, tmp2) == 2) {
        ob = find_player(lower_case(tmp1));
        if (!ob) { return; }
        /* A small delay.. */
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
    ob = find_object("/wizards/yodin/testit/erclups");
    if (!ob) { return; }
    ob->reduce_number();
}
