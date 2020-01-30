inherit "obj/monster";

reset(arg) 
{
 object money;
 object armour,weapon;
 ::reset(arg);
 if(arg) { return; }
 set_level(37);
 set_name("cinthara");
 set_alias("priestess");
 set_short("Cinthara Sharpblade the high priestess of Jhary.");
 set_long("She really looks good, doesn't she?\n");
 set_al(100); /*-100..100*/
 set_aggressive(0);
 set_animal(0);
 
 money = clone_object("obj/money");
 call_other(money, "set_money", random(500)+10 );
 move_object(money, this_object());
 set_spell_chance(20, "exs poi grs");
 set_skill("cast essence", 75);
 set_skill("cast poison", 75);
 set_skill("cast grasp", 90);
 set_skill("cast divine", 80);
 set_skill("cast heal", 80);
 set_skill("cast major", 80);
 set_skill("channel", 80);
 set_extra(1);
}

extra() 
{
 string spell_words, target_name;
 target_name = "cinthara";
 spell_words = "chl hea mjr";
 if (!query_spell() 
     && random(100) > 30 
     && query_hp() < query_max_hp()*2/3 
     &&!this_object()->query_stunned())
 {
  spell = clone_object("obj/spell");
  spell->start_spell(spell_words + " at " + target_name);
 }                        
} 
 
 
