inherit "/obj/monster";

int i;

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(40 +random(5));
    set_name("soul");
    set_alias("undead");
    set_undead(1);
    set_short("Lost soul is wandering here");
    set_long("This poor soul seems desperate, looking for a way to free himself.\n");
    set_al(0);
    set_aggressive(0);
    set_max_hp(query_max_hp() + 5000);
    set_max_hp(query_max_hp());
    set_gender(1);
    set_race("human");
    set_skill("cast essence", 50);
    set_skill("cast fire", 50);
    set_skill("cast bolt", 50);
    set_skill("mana control", 20);       
    set_skill("chanting", 40);
    set_spell_change(60,"exs fla blt");   
    chat_str = allocate(3);
         chat_str[0] =
          "Soul whines 'We all are cursed.'\n";
        chat_str[1] =
          "Soul whines 'I wish I had been wiser, not to make deals with the dark hearted.'\n";
	chat_str[2] =
	  "Soul whines 'I just couldnt keep the promise I made.\n";
	
    load_chat(15, chat_str);

}               

                            
