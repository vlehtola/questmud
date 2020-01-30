inherit "obj/monster";
object sash;
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(79+random(15));
    set_name("durand");
    set_alias("human");
    set_short("Durand the pacifist is here, moaning in his misery");
    set_long("Lord Durand is very tall man, almost 7 feet tall. His\n"
             "long white hair is becoming a bit thinner, but still\n"+
             "gives him a quite noble looks. Ruling as a Lord,\n"+
             "pacifist Durand has made many noteworthy agricultural\n"+
             "and administrative changes, but he never forgets\n"+
             "his years as a travelling preacher and teacher.\n"+
             "The look in his eyes tells you about his eternal\n"+
             "wisdom and infinite intelligence gained during the\n"+
             "numerous years spend on travelling among the peasants\n"+
             "and courts of ruler's. Lord's presence compels you to kneel\n"+
             "before him.\n");

    set_al(100);
    set_resists("electric", 20);
    set_resists("fire", 20);
    set_resists("cold", 20);
    set_aggressive(0);
    set_extra(1);
    set_max_hp(300000);
    set_hp(300000);
    set_max_sp(query_sp()/2);
    set_sp(query_max_sp());
    set_wis(query_wis()*8);
  set_str(query_str()*2);
    set_log();
    set_skill("cast divine", 100);
    set_skill("cast heal", 100);
    set_skill("cast minor", 100);
    set_skill("cast transfer", 100);
    set_skill("cast major", 100);
    set_skill("channel", 100);
    set_skill("cast essence", 100);
    set_skill("cast electric", 100);
    set_skill("cast illusion", 100);
    set_skill("mana control", 100);
    set_skill("cast lesser", 100);
    set_skill("cast holy alteration", 100);
    set_skill("mastery of medicine", 100);
    sash = clone_object("/wizards/jenny/linnake/rojut/sash.c");
    move_object(sash, this_object());
    init_command("wear sash");
}



extra() {
        int i;
        i = random(5);
        if(i==0) {
                start_spell_0();
        } else { start_spell_1(); }
}


start_spell_0() {
        string spell_words1, target_name1;
        spell_words1 = "chl hea min";
        target_name1 = "durand";
        if (!query_spell() && random(100) > 50 &&
        !this_object()->query_stunned() ) {
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
        if ( !query_spell() && random(100) > 50 &&
        !this_object()->query_stunned()) {
        spell = clone_object("guilds/obj/spell");
        move_object(spell, this_object());
        spell->start_spell(spell_words3 + " at " + lower_case(target_name3));
}
 }
