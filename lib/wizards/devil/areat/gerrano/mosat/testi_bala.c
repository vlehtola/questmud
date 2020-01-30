inherit "obj/monster";

reset(arg) {
        object money;
        object axe,leggings,bracers;
        ::reset(arg);
        if(arg) {return; }
        set_name("baladorg");
        set_alias("spirit");
        set_race("spirit");
        set_mage(1);
        set_level(85+random(20));
        set_special(15);
        set_exp(15014354);
        set_max_hp(query_hp() + 100000);
        set_int(query_int() + 300);
        set_wis(query_wis() + 100);
        set_con(query_con()*4);
        set_al(-100);
        set_gender(1);
        set_aggressive(1);
        set_short("Spirit of Baladorg, the first leader of Gerrano swamps");
        set_long("Standing well over 12 feet tall, this huge creature bears\n"+ 
                 "the crested insignia of the swamp troll community. Clothed\n"+
                 "in a sturdy looking leather jacket and matching shorts,\n"+
                 "he patrols with his hammer at his side and his whip\n"+
                 "around his belt. You get this feeling, he may posses some\n"+
                 "great secrets about Gerrano swamps.\n");
      set_skill("critical", 80);
      set_skill("enhance criticals", 75);
      set_skill("find weakness", 88);
      set_skill("deceived attack", 93);
      set_skill("bludgeons", 100);
      set_skill("round blow", 80);
      set_skill_chance("round blow", 45);
      set_skill("pound", 100);
      set_skill("throw weight", 100);
      set_skill("tumble", 40);
      set_skill("reflect spell", 100);
      set_skill("counter spell", 80);
      set_mage();
      set_spell_chance(55, "kyo brr tdr");
      set_spell_chance(65, "exs fla strm");
      set_skill("abjuration", 100);
      set_skill("cast abjuration", 100);
      set_skill("cast alteration", 100);
      set_skill("cast ice", 100);
      set_skill("cast essence", 100);
      set_skill("cast electric", 100);
      set_skill("cast storm", 100);
      set_skill("theory of electricity", 100);
      set_skill("mana control", 60);
      set_skill("chanting", 100);
      set_skill("agility", 60);
        set_log();


}


status viltteri(object ob) {

if(living(ob) && !ob->query_npc())return 1;
return 0;
}


special_move() {

object *obs;
object ob;

obs = all_inventory(environment(this_object()));

if(!obs && sizeof(obs) == 0)return;

obs = filter_array(obs,"viltteri");

ob = obs[random(sizeof(obs))];

if(!ob)return;

tell_object(ob,"Baladorg grabs you from the neck and throws you out from hes room!\n");
tell_room(environment(ob),"Baladorg throws "+ob->query_name()+" out from hes room!\n", ({ob,}));
move_object(ob,"/world/city/cs");

}
