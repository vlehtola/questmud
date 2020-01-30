inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_heart_beat(1);
    call_other(this_object(), "set_level", 90);
    call_other(this_object(), "set_name", "spirit");
    call_other(this_object(), "set_alias", "spirit");
    call_other(this_object(), "set_short", "The spirit element");
    call_other(this_object(), "set_long", "The Spirit is overwhelming. Its precense makes you truly feel puny.\n" +
                               "But it is still looking at you with a great caution, like if it is afraid of you.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_al_aggr", 200);
    call_other(this_object(), "set_aggressive", 0);
    set_log();
    set_mage(1);
    set_spell_chance(100, "exs fla blt");
    set_spell_chance(100, "exs zzt blt");
    set_spell_chance(100, "exs brr blt");
    set_skill("cast essence", 100);
    set_skill("cast fire", 100);
    set_skill("cast ice", 100);
    set_skill("cast electric", 100);
    set_skill("cast bolt", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
    set_dead_ob(this_object());
    set_resists("fire", 30);
    set_resists("physical", 30);
    set_resists("cold", 30);
    set_resists("asphyxiation", 30);
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] = "The Spirit looks at you and laughs when he thinks of your puny intellect.\n";
        chat_str[1] = "Spirit says: I must thank you for freeing me, but go now before I kill you.\n";
        chat_str[2] = "Spirit says: I will go to the four planes and destroy them!\n";
  }

    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "Sprite screams 'Die scum!'\n";
        a_chat_str[1] = "Sprite screams 'You will be CRUSHED!'\n";
    }
load_chat(30, chat_str);
load_a_chat(38, a_chat_str);

}

monster_died() {
  object monster1, monster2, monster3;
  say("As the spirit gets seriously hurt it jumps backwards and starts chanting on a spell.\n");
  say("When the spell is done he starts glowing first in red, then in green and finally in yellow.\n");
  say("And suddenly he explodes and in his place 3 smaller spirits stand. Fully healed.\n");
  monster1 = clone_object("/wizards/gynter/element/mobs/spirit_clone3.c");
  monster2 = clone_object("/wizards/gynter/element/mobs/spirit_clone2.c");
  monster3 = clone_object("/wizards/gynter/element/mobs/spirit_clone1.c");
  move_object(monster1, environment(this_object()));
  move_object(monster2, environment(this_object()));
  move_object(monster3, environment(this_object()));
  destruct(this_object());
  return 1;
}
