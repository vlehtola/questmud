inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_race("human");
    set_level(33);
    set_mage(1);
    set_name("baroness");
    set_gender(2);
    set_alias("von alset");
    set_alt_name("shop owner");
    set_short("Baroness von Alset the luxury shop owner");
    set_long("The baroness is an elderly woman but does not seem dim-witted\n" +
             "at all. This very woman has been in charge of world famous\n" +
             "von Alsets' shop over many decades now. She seems to be prepared\n" +
             "to defend her family's shop with her life.\n");
    set_al(5);
    set_log();
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Baroness arranges the objects on the shelves.\n";
        chat_str[1] =
          "Baroness mutters: 'These Mr. Billeth's candies tend to be so badly packed.'\n";
        chat_str[2] =
          "Baroness fetches a ladder so she could reach the higher shelves. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Baroness slaps you across the face. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    armour = clone_object("/wizards/nalle/area/eq/alsleggings");
    move_object(armour, this_object());
    init_command("wear leggings");

    weapon = clone_object("/wizards/nalle/area/eq/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");

   set_special(35);
}

special_move() {
  int i;
  if(!query_attack()) return;
  if(query_attack()->query_gender() == 1) {
    tell_room(environment(this_object()), short()+" kicks "+query_attack()->query_name()+
        " in the balls! OUCH!\n");
    query_attack()->hit_with_spell(80, "physical");
    query_attack()->set_stunned(6);
    return 1;
  }
  tell_room(environment(this_object()), short()+" slaps "+query_attack()->query_name()+" on the cheek!\n");
  query_attack()->hit_with_spell(100, "physical");
}
