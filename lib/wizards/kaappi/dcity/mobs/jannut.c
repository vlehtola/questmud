inherit "obj/monster";
reset(arg) {
int a;
a = random(4);
::reset(arg);
if (arg) return;
set_race("dwarf");
set_name("dwarf");
set_alias("citizen");
set_al(60);
set_aggressive(0);
set_special(100);
switch(a) {

case 0 : set_level(20+random(5));
set_short("Young dwarven citizen");
set_gender(2);
set_move_at_random(6);
set_long("A dwarven citizen walking on the street.\n"+
         "She looks relaxed and there is no marks of\n"+
         "any worries on his face. She is quite beautiful.\n");
break;

case 1 : set_level(20+random(5));
set_short("Young dwarven citizen");
set_gender(1);
set_move_at_random(8);
set_alt_name("dwarf");
set_long("A dwarven citizen walking on the street.\n"+
         "He looks relaxed and there is no marks of\n"+
         "any worries on his face.\n");
break;

case 2 : set_level(25+random(8));
set_short("A dwarven citizen");
set_gender(2);
set_move_at_random(8);
set_long("A hurry looking dwarven citizen.\n"+
         "She seems to be very breathless as she\n"+
         "is running on the street.\n");
break;

case 3 : set_level(25+random(8));
set_short("A dwarven citizen");
set_gender(1);
set_move_at_random(6);
set_long("A hurry looking dwarven citizen.\n"+
         "He has a very long brown bead, and he\n"+
         "seems to be very breathless as he is\n"+
         "running on the street.\n");
break;
  }
}
special_move() {
  object ob;
  ob = present("guard", environment(this_object()));
  if(attacker_ob && ob) {
  tell_room(environment(this_object()), "Guard yells: 'Fighting in our city is not allowed!'\n");
  ob->attack_object(attacker_ob);
return 1; }
}
