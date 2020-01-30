inherit "obj/monster";

reset(arg) 
{
 object money;
 object armour,weapon;
 ::reset(arg);
 if(arg) { return; }
 set_level(43);
 set_name("beery");
 set_alias("bartender");
 set_short("Beery Bloodaxe the bartender");
 set_long("Beery Bloodaxe is an old and fat (even for the dwarves) dwarf\n"+
          "who is nonetheless quick and agile, already at your service. You\n"+
          "may ask him for a list of drinks he offers but some drinks are\n"+
          "only suitable for REAL men!\n");
 set_al(0);
 set_aggressive(0);
 set_animal(0);
 
 money = clone_object("obj/money");
 call_other(money, "set_money", random(5000)+2031 );
 move_object(money, this_object());
 set_skill("tumble",80);
 set_skill("deceived attack",100);
 set_skill("doublehit",100);
 set_skill("defence overall",95);
 set_skill("throw weight",90);
 set_skill("enhance criticals",100);
 set_skill("counter spell",0);
}
                                                                                                                       
