inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(12);
    set_gender(1);
    set_name("miner");
    set_short("A miner gone insane from the horrors he has witnessed");
    set_long("Seeing his friends ripped apart piece by piece has been too much"+
             "for this poor miner.\n You could almost pity him if he were not"+
      "so busy trying to kill you...\n");
    set_al(0);
    set_aggressive(1);
    set_race("human");
 
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The madman shouts:'YOU WILL NEVER TAKE ME NOW!'\n";
    }
    load_a_chat(15, a_chat_str);
    weapon = clone_object("/wizards/tiergon/eq/pick");
    move_object(weapon, this_object());
    init_command("wield pick");
}
