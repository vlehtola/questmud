inherit "obj/monster";

reset(arg) {
string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
set_level(50);
set_name("entity");
set_max_hp(query_max_hp() * 5);
set_hp(query_max_hp());

set_alias("entity");
set_short("A demonic guardian entity summoned by Nyx ");
set_long("This horned and winged creature is the guardian entity of Nyx. It has been summoned \n"
         "from deepest pits of hell to protect his creator Nyx.\n");
set_al(-50);
    set_aggressive(1);
    set_extra(1);
    set_spell_chance(70, "exs fla blt");
     set_skill("critical", 100);
	 set_skill("attack", 300);
	 set_skill("channel", 300);
	 set_skill("cast bolt", 150);
	 set_skill("chanting", 400);
	 set_skill("cast essence", 150);
	 set_skill("bare hands", 300);
	 set_skill("cast earth", 350);
    set_skill("mana control", 350);
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast major", 80);
    set_skill("channel", 80);

     if (!a_chat_str) {
	         a_chat_str = allocate(3);
	         a_chat_str[0] = "Entity thunders: Nyx is the bringer of chaos!\n";
	         a_chat_str[1] = "Entity starts chanting some strange demonic runes\n";
                  }



}
