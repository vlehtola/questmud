inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(10);
    set_name("spirit");
    set_short("A non-corpseal spirit");
    set_long("This spirit is all transparent and you even have some difficulties to see it.\n");
    set_al(0);
    set_spell_chance(50, "exs fla grs");
    set_aggressive(1);
    set_block_dir("out");
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast grasp", 50);
    set_skill("mana control", 20);
    set_skill("chanting", 40);
}

catch_tell(str) {
    string giver;
    object ob;
    if (sscanf(str, "%s gives you [object_name].", giver) == 1) {
    if (!present("[object_name]", this_object) { return; }	
    ob = present(giver,environment(this_object()));
    if (ob && !ob->query_quest("[quest_name]")) {
	tell_object(ob, "You have completed the quest.\n");
	ob->set_quests("[quest_name]");
	/* Add rewards here if you want. */
	ob->add_exp(100000);
    }
}
