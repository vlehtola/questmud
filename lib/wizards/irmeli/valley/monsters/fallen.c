inherit "obj/monster";

status summoned;

reset(arg) {
    object armour,armour2,armour3,weapon;
    int i;
::reset(arg);
if (arg) { return; }
    set_level(83);
    set_alias("victoria");
   set_name("enchantress");
    set_short("Enchantress Victoria, the fallen angel");
    set_long("An beatiful angel called as 'Victoria'. She is very beatiful, especially\n"+
             "her long, blonde hair, blue eyes, soft, peaches-and-cream skin and\n"+
             "perfect body. She is so beatiful, that it's hard to loosen your eyes\n"+
             "from her. Two, big and white wings are growing from her backbone,\n"+
             "improving her look. Her enchantment power can be irresistible.\n");
         
    set_max_hp(90000);
    set_hp(90000);
    set_exp(4000000);
    set_al(60);
    set_gender(2);
    set_race("human");
    set_int(query_int()*2);
    i = random(2);
    set_aggressive(0);
    set_log();
    set_mage(1);

    weapon = clone_object("/wizards/irmeli/valley/eq/whip");
    move_object(weapon, this_object());
    init_command("wield whip");

    if(!i) {
 
      armour = clone_object("/wizards/irmeli/valley/object/heart");
      move_object(armour, this_object());

      armour2 = clone_object("/wizards/irmeli/valley/eq/wreath");
      move_object(armour2, this_object());
      init_command("wear wreath");
    } else {
      armour3 = clone_object("/wizards/irmeli/valley/eq/gloves");
      move_object(armour3, this_object());
      init_command("wear gloves");
    }

    set_special(50); /* 50% chance every turn to call_other special_move() */
}

special_move() {
  if(query_hp() > query_max_hp() / 2) return 0;
  if(summoned) return 0;
  summoned = 1;
  move_object(clone_object(rnd_monster()), environment(this_object()));
  write("The Enchantress summons a Minion to help her!\n");
}

string rnd_monster() {
  int i;
  i = random(3);
  switch(i) {
    case 0: return "/wizards/irmeli/valley/monsters/headhunter";
    case 1: return "/wizards/irmeli/valley/monsters/priestess";
    case 2: return "/wizards/irmeli/valley/monsters/assassin";
  }
  return "error";
}
