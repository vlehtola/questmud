inherit "obj/monster";
reset(arg) {
object armour,weapon;
int a;
a = random(4);
::reset(arg);
if (arg) return;
set_race("dwarf");
set_name("dwarf");
set_alias("miner");
set_al(60);
set_aggressive(0);
switch(a) {

case 0 : set_level(20+random(5));
set_short("Young dwarven miner");
set_gender(2);
set_alt_name("miner");
set_long("A small dwarven miner.\n"+
         "She is wearing only dirty clothes and she has a mining pick\n"+
         "in her hand. Seems that she is very busy right now.\n");
break;

case 1 : set_level(20+random(5));
set_short("Young dwarven miner");
set_gender(1);
set_alt_name("dwarf");
set_long("A small but muscular dwarven miner.\n"+
           "He is wearing only dirty clothes and he has a mining pick\n"+
           "in his hand. Seems that he is very busy right now.\n");
break;

case 2 : set_level(25+random(8));
set_short("A dwarven miner");
set_gender(2);
set_alt_name("dwarf");
set_long("A small and ugly dwarven miner.\n"+
         "She is wearing only dirty clothes and she has a mining pick\n"+
         "in her hand. Seems that she is very busy right now.\n");
break;

case 3 : set_level(25+random(8));
     set_short("A dwarven miner");
     set_gender(1);
     set_alt_name("dwarf");
set_long("A small but muscular dwarven miner.\n"+
         "He is wearing only dirty clothes and he has a mining pick\n"+
         "in his hand. Seems that he is very busy right now.\n");
break;
  }
weapon = clone_object("/wizards/kaappi/mine/kamat/pick.c");
move_object(weapon, this_object());
init_command("wield pick");

armour = clone_object("/wizards/kaappi/mine/kamat/vaate.c");
move_object(armour, this_object());
init_command("wear clothes");
 }
