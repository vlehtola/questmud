inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) { return; }
 set_level(37);
 set_name("cinthara");
 set_alias("priestess");
 set_short("Cinthara, the high priestess");
 set_long("The high priestess is named Cinthara. She is perfect looking, her blond,\n"+
          "long hair is curly, body is curvy and her face are so beatiful, that\n"+
          "every adventurer would like to marry her.\n");
 set_al(100);
 set_race("dwarf");
 set_gender(2);
 set_skill("cast essence", 75);
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
 spell_words = "chl hea mar";
 if (!query_spell() 
     && random(100) > 30 
     && query_hp() < query_max_hp()*2/3 
     &&!this_object()->query_stunned())
 {
  spell = clone_object("obj/spell");
  spell->start_spell(spell_words + " at " + target_name);
 }                        
} 
 
 
