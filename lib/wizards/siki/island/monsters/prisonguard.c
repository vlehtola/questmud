inherit "obj/monster";

    string chat_str;
    object key,weapon;

reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    

    set_level(21+random(2));
    set_name("giant guard");
    set_alias("guard");
    set_race("giant");
    set_alt_alias("prison guard");
    set_short("A giant guarding the prison");
    set_long("A tall giant standing proudly infront of the prison door. He\n"+
             "is taking his job extremely serious and he holds his club with\n"+
             "all the strength he can gather, what makes his arm swet.\n");

             
   
              
              
    set_al(10);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(2);
 chat_str[0] = "The giant guard booms 'Lypt gave me a special task. I'm not allowed\n"+
               "to let anyone enter.'\n";
 chat_str[1] = "The giant guard booms 'The orcs are so stupid! We enslaved them without\n"+
               "any problems!' and laughs.\n";

   

}
    load_chat(2, chat_str);
    key = clone_object("/wizards/siki/island/obj/prisonkey");
    move_object(key,this_object());
    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");


}
