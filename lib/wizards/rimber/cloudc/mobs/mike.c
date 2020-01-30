inherit "obj/monster";
int number_of_angels;

reset(arg) {
 object weapon, shield;
 object bo;
 object armour, brac;
 ::reset(arg);
 number_of_angels = 0;
 if(arg) return;
 set_level(90);
 set_name("michael");
 set_alias("archangel");
 set_short("Archangel Michael");
 set_long("Long white wings and so on..\n");
 set_al(50);
 set_race("angel");
 set_gender(1);

 shield = clone_object("/wizards/rimber/cloudc/obj/gshield.c");
 move_object(shield, this_object());
 init_command("wield shield");
 weapon = clone_object("/wizards/rimber/cloudc/obj/asword.c");
 move_object(weapon, this_object());
 init_command("wield sword");
 armour = clone_object("/wizards/rimber/cloudc/obj/marmour.c");
 move_object(armour, this_object());
 init_command("wear breastplate");
 switch(random(2)) {
 case 1:
 bo = clone_object("/wizards/rimber/cloudc/obj/gsandals.c");
 move_object(bo, this_object());
 init_command("wear sandals");
 break;
 case 0:
 brac = clone_object("/wizards/rimber/cloudc/obj/bracut.c");
 move_object(brac, this_object());
 init_command("wear bracelets");
 break;
 }
 set_log(1);
 set_extra(1);
}

extra() {
 object angel;
 if(!attacker_ob) { return; }
 if(number_of_angels == 3) { return; }
 if(random(number_of_angels + 1) == number_of_angels) {
  angel = clone_object("/wizards/rimber/cloudc/mobs/angel.c");
  move_object(angel, environment(this_object()));
   say("Michael shouts: 'Come my child!'\n");
   number_of_angels += 1;
    }
}


reduce_number() {
   number_of_angels -= 1;
}
