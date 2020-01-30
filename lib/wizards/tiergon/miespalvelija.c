inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(666);
    set_gender(1);
    set_name("Tiergonin petomainen miespalvelija");
    set_alias("miespalvelija");
    set_short("Tiergonin petomainen miespalvelija");
    set_long("Tiergonin petomainen miespalvelija on itseasiassa valtava frakkiin pukeutunu karhu\n"+
             "The bear growls:'If you don't speak finnish, you shouldn't be here in the first place\n");
    set_al(10);
    set_aggressive(0); 
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Miespalvelija grabs you in a bearhug\n";
    }
    load_a_chat(20, a_chat_str);
    
    weapon = clone_object("/wizards/tiergon/eq/palvelijahammer");
    move_object(weapon, this_object());
    init_command("wield hammer");
}
