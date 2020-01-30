inherit "obj/monster";
object tunic, staff;
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("hring");
        set_alias("priest");
        set_level(30);
        set_gender(1);
        set_al(50);
        set_hp(50000);
        set_max_hp(50000);
        set_log();
        set_race("high elf");
        set_short("Hring the high priest");
        set_long("He is wearing a white tunic which glitters in light. Looking at his\n"+
                 "face you get feeling of great wisdom that this priest posses.\n");
        set_extra(1);
        set_skill("cast divine", 90);
        set_skill("cast heal", 90);
        set_skill("cast major", 90);
        set_skill("channel", 90);
        set_skill("chanting", 50);
        set_skill("mastery of medicine", 50);
        set_skill("tumble", 30);
        staff = clone_object("/wizards/neophyte/city/eq/staff");
        move_object(staff, this_object());
        init_command("wield staff");
                             if (!chat_str) {
                                         chat_str = allocate(1);
                                         chat_str[0] =
                                 "Hring says 'We have a quite problem with the warlocks'\n";
                                     }
            load_chat(3, chat_str);

}

extra() {
    string spell_words, target_name;
    target_name = "hring";
    spell_words = "chl hea mjr";


    if (!query_spell() && random(100) > 50 && query_hp() < query_max_hp() / 2
&&
        !this_object()->query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
    }
}
