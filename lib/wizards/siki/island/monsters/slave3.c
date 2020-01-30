inherit "obj/monster";


object weapon;
string chat_str;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(15+random(2));
    set_name("orc slave");
    set_alias("slave");
    set_race("orc");
    set_exp(query_exp()*1.36);
    set_short("An orc slave");
    set_long("A strong but starving orc slave working here in the mines. His ribs\n"+
             "can be seen through his dirty skin. He has large bruises all over\n"+
             "his body.\n");


    if (!chat_str) {
        chat_str = allocate(1);
 chat_str[0] = "The orc slave hits the wall with his pick.\n";

}
load_chat(3, chat_str);
    set_al(0);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);


    weapon = clone_object("/wizards/siki/island/eq/pick");
    move_object(weapon,this_object());
    init_command("wield pick axe");


}
