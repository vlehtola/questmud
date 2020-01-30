inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(8);
    set_gender(1);
    set_name("miner");
    set_short("A tired miner leaning against his pick");
    set_long("The miner has become completely exhausted from his"+ 
             "struggle to reach the surface.\n");
    set_al(10);
    set_aggressive(0); 
    set_race("human");

if (!chat_str) {
        chat_str = allocate(2); 
        chat_str[0] =
"The miner rasps:'We woke a lich lord and the creature summoned fiends to slay us.'\n";
chat_str[1] =
  "'The lower levels are are filled with creatures from the Abyss.', the miner warns you\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The sighs and swings his pick tiredly\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);
    
    weapon = clone_object("/wizards/tiergon/eq/pick");
    move_object(weapon, this_object());
    init_command("wield pick");
}
