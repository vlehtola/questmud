inherit "obj/monster";

    object weapon;
    string chat_str;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(19+random(2));
    set_name("giant guard");
    set_alias("guard");
    set_exp(query_exp()*0.8);
    set_race("giant");
    set_short("A furious giant guard");
    set_long("A giant watching the slaves and keeping order. His skin\n"+
             "is dirty and hairy.\n");


    set_al(10);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);

    if (!chat_str) {
        chat_str = allocate(2);
 chat_str[0] = "The giant booms 'These orcs are pathetic.'\n";
 chat_str[1] = "The giant tries to look important.\n";

   

}
    load_chat(5, chat_str);    

    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");
}

