inherit "obj/monster";

reset(arg) {
    object armour,armour2,armour3;
    int i;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_name("healer");
    set_alias("priestess");
    set_short("The High Priestess, Healer of the Enchantress (charmed)");
    set_long("She is a beatiful woman, with her blond and long hair, beatiful and soft\n"+
             "skin, perfect body and long, smooth and thin legs. Her sky-blue eyes are\n"+
             "sparkling behind her hair. Often the healers are females, because females\n"+
             "want to take care of people. She can cure wounds, serious or deadly, if\n"+
             "necessary. She is one out of three minions, minions of the Enchantress.\n");
    set_al(50);
    set_aggressive(1);
    set_extra(1);
    set_log();
    set_max_hp(35000);
    set_hp(35000);
    set_gender(2);
    i = random(3);
    set_race("human");
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast major", 80);
    set_skill("channel", 80);

    if(i==0) { armour = clone_object("/wizards/irmeli/valley/eq/bands.c");
    move_object(armour, this_object());
    init_command("wear bands");
}
    if(i==1) { armour = clone_object("/wizards/irmeli/valley/eq/shoes.c");
    move_object(armour,this_object());
    init_command("wear shoes");
}     
    if(i==2) { armour = clone_object("/wizards/irmeli/valley/eq/cardigan.c");
    move_object(armour,this_object());
    init_command("wear cardigan");

}
}
extra() {
    string spell_words, target_name;
    object target_ob;
    target_name = "victoria";
    spell_words = "chl hea mar";
    target_ob = present(target_name);

  /* Must have only half hp left, random 100 must be lower than 50 and
     must not be stunned to start casting. */

    if (!query_spell() && random(100) > 50 && target_ob && 
        target_ob->query_hp() < target_ob->query_max_hp() / 2 &&
        !this_object()->query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
    }
 }

