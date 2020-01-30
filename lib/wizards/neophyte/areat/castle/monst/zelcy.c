inherit "obj/monster";
object cloak;
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(45);
    set_name("zelcy");
    set_alias("healer");
    set_short("Zelcy the royal healer");
    set_long("Zelcy is the royal healer of this castle and loyal friend of pidur.\n");
    set_al(50);
    set_aggressive(0);
    set_extra(1);
    set_special(100);
    set_max_hp(query_hp()*2+random(150000));
    set_hp(query_max_hp());
    set_max_sp(query_sp()/2);
    set_sp(query_max_sp());
    set_wis(query_wis()*5);
    set_log();
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast minor", 80);
    set_skill("cast transfer", 90);
    set_skill("cast major", 100);
    set_skill("channel", 100);
    set_skill("cast essence", 100);
    set_skill("cast electric", 100);
    set_skill("cast illusion", 100);
    set_skill("mana control", 80);
    set_skill("cast lesser", 100);
    set_skill("cast holy alteration", 100);
    set_skill("mastery of medicine", 100);
    cloak = clone_object("/wizards/neophyte/areat/castle/obj/cloak");
    move_object(cloak, this_object());
    init_command("wear cloak");
}

extra() {
	int i;
	i = random(5);
	if(i==0) {
		start_spell_0();
	} else { start_spell_1(); }
}



special_move() {
 object ob;
 ob = present("pidur", environment(this_object()));
 if(attacker_ob && ob) {
   ob->attack_object(attacker_ob);
   return 1;
 }

}

start_spell_0() {
        string spell_words1, target_name1;
        spell_words1 = "exs zzt ils";
        target_name1 = "zelcy";
        if (!query_spell() && random(100) > 50 &&
        !this_object()->query_stunned() &&
        !this_object()->query_mirror_image()) {
        spell = clone_object("guilds/obj/spell");
        move_object(spell, this_object());
        spell->start_spell(spell_words1 + " at " + target_name1);
}
}

start_spell_1() {
        object ob,ob1;
        string spell_words3, target_name3;
                ob = this_object()->query_attacker();
                ob1 = ob->query_name();
        spell_words3 = "chl xfr min";
        target_name3 = ob1;
        if (!query_spell() && random(100) > 50 &&
!this_object()->query_stunned()) {
        spell = clone_object("guilds/obj/spell");
        move_object(spell, this_object());
        spell->start_spell(spell_words3 + " at " + lower_case(target_name3));
}
}