inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    set_level(90);
    set_name("talos");
    set_alias("mage");
    set_alt_name("master");
    set_short("Talos the Master Mage");
    set_long("Talos is the master of the apprentice mage guild of "+
"Duranghom. His bearded face reflects great wisdom and peace.\n");
    set_al(60);
    set_al_aggr(300);
    set_aggressive(0);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Talos says: 'See 'help spellcasting' to learn how to cast spells'.\n";
        chat_str[1] =
          "Talos says: 'Mana control is important, train it'.\n";
        chat_str[2] =
"Talos says: 'Chanting is less important than the 'cast' skills'.\n";
        chat_str[3] =
"Talos says: 'Cast earth only allows you to inflict physical damage. Try "+
"to learn knowledge of other elements as soon as possible'.\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "The Master shouts: 'Die BASTARD!'.\n";
        a_chat_str[1] =
"The Master says: 'Soon Sinrad will be here, and you will die by his sword!'\n";
    }

    load_chat(5, chat_str);
    load_a_chat(20, a_chat_str);

    set_mage(10);
    set_log();
}




