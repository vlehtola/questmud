inherit "/obj/monster";

object ob;
int i;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(45+random(5));
    set_name("soul");
    set_alias("undead");
    set_undead(1);
    set_short("Lost soul is wandering here");
    set_long("This poor soul seems desperate, looking for a way to free himself.\n");
    set_max_hp(query_max_hp() + 5000);
 set_max_hp(query_max_hp());    
set_al(0);
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast bolt", 50);
    set_skill("mana control", 20);       
    set_skill("chanting", 40);
    set_spell_chance(40,"exs fla blt");      
 set_aggressive(0);
    set_gender(1);
    set_race("human");
        chat_str = allocate(3);
         chat_str[0] =
          "Soul whines 'We all failed to fullfill the task of our master'\n";
	chat_str[2] =
	  "Soul whines 'He kept his part of the deal, but he did not tell us\n" +
	  "what would happen if we could not accomplish our part of the deal!'\n";
	
    load_chat(15, chat_str);

}               

                                                                                                             