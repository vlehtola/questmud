inherit "obj/monster";

    string chat_str;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(17+random(2));
    set_name("giant guard");
    set_alias("guard");
    set_race("giant");
    set_short("A young giant guard");
    set_long("A young but strong giant spending time in the guard post.\n"+
             "He looks very self-confident.\n");


    set_al(10);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(2);
 chat_str[0] = "The young giant booms 'Someday I will show my might. This\n"+
               "is ridiculous.'\n";
 chat_str[1] = "The young giant mutters something quietly and spits on the\n"+
               "ground.\n";

   

}
    load_chat(3, chat_str);    
}

