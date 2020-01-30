inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(10);
    set_gender(1);
    set_race("human");
    set_name("miner");
    set_short("A strong miner resting on a bed");
    set_long("The young miner is still in pretty good shape.\n"+
             "He must have been sleeping when the attack came.\n");
    set_al(10);
    set_aggressive(0); 
if (!chat_str) {
        chat_str = allocate(2); 
        chat_str[0] =
    "A fire crackles merrily in the fireplace.\n";
chat_str[1] =
  "The young miner yawns and scratches his back.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The miner stumbles about, blinking his eyes.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+21);
    move_object(money, this_object());
    
    weapon = clone_object("/wizards/tiergon/eq/pick");
    move_object(weapon, this_object());
    init_command("wield pick");
}
