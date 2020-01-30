/* This is a monster cloned by the antqueen to help it. 
   It follows leaving players.
*/

inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    set_level(10);
    set_exp(query_exp()/2);
    set_name("small ant");
    set_alias("ant");
    set_short("A small ant");
    set_long("This is a small ant just born from an egg. Still it seem very\n" +
             "aggressive. It has small claws, which already have some strenght in\n" + 
             "them.\n");
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
    ob = find_object("/world/monsters/antqueen");
    if (!ob) { return; }
    ob->reduce_number();
}
