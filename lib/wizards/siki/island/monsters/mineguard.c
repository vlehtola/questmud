inherit "obj/monster";

    object weapon,armour;
    string chat_str;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(25+random(3));
    set_name("guard");
    set_alias("mine guard");
    set_alt_alias("giant guard");
    set_race("giant");

    set_short("A tall and muscular giant guard");
    set_long("A strong looking giant standing proudly infront of the entrance\n"+
             "of the cave. He stares straight into yours eyes as you take a\n"+
             "quick glance at him.\n");



    set_al(15);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);

    if (!chat_str) {
        chat_str = allocate(1);
 chat_str[0] = "The giant guard booms 'We enslaved the orcs.' and laughs\n";


   }
    load_chat(2, chat_str);    

    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");
    armour = clone_object("/wizards/siki/island/eq/plate");
    move_object(armour,this_object());
    init_command("wield chain");
}

