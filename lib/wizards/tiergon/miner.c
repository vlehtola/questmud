inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(7);
    set_gender(1);
    set_name("miner");
    set_short("A badly wounded miner struggling to reach the surface");
    set_long("The old miner has been wounded by some ferocious creature.\n"+
             "From the way his breathing labours you guess he won't live"+
     " long.\n");
    set_al(10);
    set_aggressive(0); 
    set_race("human");

if (!chat_str) {
        chat_str = allocate(2); 
        chat_str[0] =
"The miner whispers:'We mined very, very deep. We were greedy and discovered a vein of gold richer than you can imagine.\n";
chat_str[1] =
  "The miner grunts:'There, deep underneath, we disturbed the peace of some ancient creature whom the gods had intended to stay frozen.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The miner looks at you sadly\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);
    
    
    weapon = clone_object("/wizards/tiergon/eq/pick");
    move_object(weapon, this_object());
    init_command("wield pick");
}
