inherit "obj/monster";

    object weapon;
    string chat_str;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(19+random(2));
    set_name("giant guard");
    set_alias("guard");
    set_race("giant");
    set_short("A cruel giant guard");
    set_long("A strong giant guard with an evil grin on his face. He enjoys the pain\n"+
             "he causes to the slaves.\n");


    set_al(-5);
    set_aggressive(0);
    set_move_at_random(10);
    set_al_aggr(400);
    set_gender(1);

    if (!chat_str) {
        chat_str = allocate(1);
 chat_str[0] = "The giant guard grins evilly and takes a better grip of the whip.\n";


   

}
    load_chat(2, chat_str);    

    weapon = clone_object("/wizards/siki/island/eq/whip");
    move_object(weapon,this_object());
    init_command("wield whip");
}

